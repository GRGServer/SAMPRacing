package net.grgserver.languagestringeditor;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class StringList extends JTable
{
	public StringList()
	{
		super();

		String[] columns = {"ID", "English", "German", "References"};

		DefaultTableModel tableModel = new DefaultTableModel(1, columns.length);
		tableModel.setColumnIdentifiers(columns);

		this.setModel(tableModel);
	}
}
