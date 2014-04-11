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
import java.io.IOException;

public class Main extends JFrame
{
	private boolean changed;

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

		this.reload();

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
				Main.this.reload();
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
				Main.this.save();
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

		this.setJMenuBar(menuBar);
	}

	private void createStringList()
	{
		this.add(new JScrollPane(new StringList()));
	}

	private void quit()
	{
		if (Main.this.changed)
		{
			switch (JOptionPane.showConfirmDialog(null, "There are unsaved changed!\n\nDo you want to save before quit?", "Unsaved changes", JOptionPane.YES_NO_CANCEL_OPTION))
			{
				case JOptionPane.YES_OPTION:
					if (Main.this.save())
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

	private void reload()
	{
		JOptionPane.showMessageDialog(null, "Reload");
	}

	private boolean save()
	{
		JOptionPane.showMessageDialog(null, "Save");
		return true;
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

		SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				new Main();
			}
		});
	}
}
