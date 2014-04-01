package net.grgserver.includesupdater;

import java.io.File;
import java.io.IOException;
import java.nio.file.Paths;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		String serverPath = Paths.get(new File(Main.class.getProtectionDomain().getCodeSource().getLocation().getPath()).getAbsolutePath()).getParent().getParent().getParent().getParent().toString();

		IncludeWriter includesWriter = new IncludeWriter(serverPath + File.separator + "includes", "grgserver", "main.inc");

		includesWriter.addGroup("Defines");
		includesWriter.addInclude("localconfig.inc");
		includesWriter.addInclude("constants.inc");
		includesWriter.addInclude("macros.inc");

		includesWriter.addDirectory("structures");

		includesWriter.addGroup("Global variables");
		includesWriter.addInclude("globals.inc");
		includesWriter.addInclude("forwards.inc");

		includesWriter.addDirectory("functions");
		includesWriter.addDirectory("callbacks");
		includesWriter.addDirectory("dialogs");
		includesWriter.addDirectory("timers");
		includesWriter.addDirectory("commands");

		includesWriter.close();

		System.out.println("Done");
	}
}