package net.grgserver.includesupdater;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class IncludeWriter
{
	private final FileWriter fileWriter;
	private final String fullIncludesPath;
	private final String subPath;
	private boolean lineWritten;

	public IncludeWriter(String includesPath, String subPath, String mainIncludeFile) throws IOException
	{
		this.fullIncludesPath = includesPath + File.separator + subPath;

		System.out.println("Updating includes in '" + this.fullIncludesPath + "'...");

		this.fileWriter = new FileWriter(this.fullIncludesPath + File.separator + mainIncludeFile);
		this.subPath = subPath;
	}

	public void addGroup(String name) throws IOException
	{
		// Add an empty line if this is not the first line
		if (this.lineWritten)
		{
			this.writeLine("");
		}

		this.writeLine("// " + name);
	}

	public void addInclude(String name) throws IOException
	{
		this.writeLine("#include <" + (this.subPath + File.separator + name).replace("\\", "/") + ">");
	}

	public void addDirectory(String path) throws IOException
	{
		File directory = new File(this.fullIncludesPath + File.separator + path);

		if (!directory.isDirectory())
		{
			return;
		}

		File[] files = directory.listFiles();

		Arrays.sort(files);

		this.addGroup(path);

		for (int index = 0; index < files.length; index++)
		{
			if (files[index].isFile())
			{
				this.addInclude(path + File.separator + files[index].getName());
			}
		}
	}

	public void writeLine(String string) throws IOException
	{
		this.lineWritten = true;
		this.fileWriter.write(string + "\n");
	}

	public void close() throws IOException
	{
		this.fileWriter.close();
	}
}