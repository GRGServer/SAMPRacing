package net.grgserver.todofinder;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class DirectoryScanner
{
	private List<File> fileList;

	public void add(String path)
	{
		this.fileList = new ArrayList<>();

		this.recursiveScan(path);
	}

	public File[] getFileList()
	{
		return this.fileList.toArray(new File[this.fileList.size()]);
	}

	private void recursiveScan(String path)
	{
		File directory = new File(path);

		File[] files = directory.listFiles();

		if (files == null)
		{
			return;
		}

		for (File file : files)
		{
			if (file.isFile())
			{
				String fileName = file.getName();
				if (fileName.endsWith(".inc") || fileName.endsWith(".pwn"))
				{
					this.fileList.add(file);
				}
				continue;
			}

			if (file.isDirectory())
			{
				this.recursiveScan(file.getAbsolutePath());
			}
		}
	}
}