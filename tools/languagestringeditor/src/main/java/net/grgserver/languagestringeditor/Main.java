package net.grgserver.languagestringeditor;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.KeyStroke;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;
import java.nio.file.Paths;

public class Main extends JFrame
{
	private static String serverPath;

	private StringFile stringFile;
	private StringList stringList;
	private int lastGotoId;
	private String lastSearchString;

	public Main()
	{
		super("Language String Editor");

		try
		{
			this.setIconImage(ImageIO.read(this.getClass().getResourceAsStream("/icon.png")));
		}
		catch (IOException exception)
		{
			exception.printStackTrace();
		}

		this.setPreferredSize(new Dimension(800, 500));
		this.pack();
		this.setLocationRelativeTo(null);// Center the frame

		this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);

		this.createMenu();
		this.createStringList();

		this.setVisible(true);

		this.stringFile = new StringFile(this.stringList);

		this.addWindowListener(new WindowAdapter()
		{
			@Override
			public void windowClosing(WindowEvent event)
			{
				Main.this.quit();
			}
		});
	}

	private void createMenu()
	{
		JMenuBar menuBar = new JMenuBar();

		JMenu fileMenu = new JMenu("File");

		JMenuItem reloadMenuItem = new JMenuItem("Reload");
		reloadMenuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_R, KeyEvent.CTRL_MASK));
		reloadMenuItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				Main.this.stringFile.load();
			}
		});
		fileMenu.add(reloadMenuItem);

		JMenuItem saveMenuItem = new JMenuItem("Save");
		saveMenuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, KeyEvent.CTRL_MASK));
		saveMenuItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				Main.this.stringFile.save();
			}
		});
		fileMenu.add(saveMenuItem);

		fileMenu.add(new JSeparator());

		JMenuItem quitMenuItem = new JMenuItem("Quit");
		quitMenuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F4, KeyEvent.ALT_MASK));
		quitMenuItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				Main.this.quit();
			}
		});
		fileMenu.add(quitMenuItem);

		menuBar.add(fileMenu);

		JMenu editMenu = new JMenu("Edit");

		JMenuItem gotoIdmenuItem = new JMenuItem("Goto ID");
		gotoIdmenuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_G, KeyEvent.CTRL_MASK));
		gotoIdmenuItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				String string = (String) JOptionPane.showInputDialog(null, "Enter the ID you want to go to.", "Goto ID", JOptionPane.QUESTION_MESSAGE, null, null, Integer.toString(Main.this.lastGotoId));
				if (string != null && !string.isEmpty())
				{
					Main.this.lastGotoId = new Integer(string);
					if (!Main.this.stringList.gotoId(Main.this.lastGotoId))
					{
						JOptionPane.showMessageDialog(null, "The ID was not found!", "Goto ID", JOptionPane.ERROR_MESSAGE);
					}
				}
			}
		});
		editMenu.add(gotoIdmenuItem);

		JMenuItem searchMenuItem = new JMenuItem("Search");
		searchMenuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F, KeyEvent.CTRL_MASK));
		searchMenuItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				String string = (String) JOptionPane.showInputDialog(null, "Enter the string you want to search for.", "Search string", JOptionPane.QUESTION_MESSAGE, null, null, Main.this.lastSearchString);
				if (string != null && !string.isEmpty())
				{
					Main.this.lastSearchString = string;
					if (!Main.this.stringList.searchString(Main.this.lastSearchString))
					{
						JOptionPane.showMessageDialog(null, "The string was not found!", "Search string", JOptionPane.ERROR_MESSAGE);
					}
				}
			}
		});
		editMenu.add(searchMenuItem);

		JMenuItem searchNextMenuItem = new JMenuItem("Search next");
		searchNextMenuItem.setAccelerator(KeyStroke.getKeyStroke("F3"));
		searchNextMenuItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				if (Main.this.lastSearchString == null || Main.this.lastSearchString.isEmpty())
				{
					String string = (String) JOptionPane.showInputDialog(null, "Enter the string you want to search for.", "Search string", JOptionPane.QUESTION_MESSAGE, null, null, Main.this.lastSearchString);
					if (string == null || string.isEmpty())
					{
						return;
					}

					Main.this.lastSearchString = string;
				}

				if (!Main.this.stringList.searchString(Main.this.lastSearchString))
				{
					JOptionPane.showMessageDialog(null, "The string was not found!", "Search string", JOptionPane.ERROR_MESSAGE);
				}
			}
		});
		editMenu.add(searchNextMenuItem);

		menuBar.add(editMenu);

		this.setJMenuBar(menuBar);
	}

	private void createStringList()
	{
		this.stringList = new StringList();

		this.add(new JScrollPane(this.stringList));
	}

	private void quit()
	{
		if (Main.this.stringList.isChanged())
		{
			switch (JOptionPane.showConfirmDialog(null, "There are unsaved changed!\n\nDo you want to save before quit?", "Unsaved changes", JOptionPane.YES_NO_CANCEL_OPTION))
			{
				case JOptionPane.YES_OPTION:
					if (Main.this.stringFile.save())
					{
						System.exit(0);
					}
					break;
				case JOptionPane.NO_OPTION:
					System.exit(0);
					break;
			}
		}
		else
		{
			System.exit(0);
		}
	}

	public static String getServerPath()
	{
		return Main.serverPath;
	}

	public static void setServerPath(String path)
	{
		Main.serverPath = path;
	}

	public static void main(String[] args)
	{
		try
		{
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		}
		catch (Exception exception)
		{
			exception.printStackTrace();
		}

		Main.setServerPath(Paths.get(new File(Main.class.getProtectionDomain().getCodeSource().getLocation().getPath()).getAbsolutePath()).getParent().getParent().getParent().getParent().toString());

		SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				new Main();
			}
		});
	}
}
