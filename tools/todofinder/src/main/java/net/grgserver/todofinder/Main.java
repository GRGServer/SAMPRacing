package net.grgserver.todofinder;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.nio.file.Paths;
import java.util.Arrays;

public class Main
{
	public static void main(String[] args) throws Exception
	{
		String serverPath = Paths.get(new File(Main.class.getProtectionDomain().getCodeSource().getLocation().getPath()).getAbsolutePath()).getParent().getParent().getParent().getParent().toString();

		DirectoryScanner scanner = new DirectoryScanner();

		scanner.add(serverPath + File.separator + "filterscripts");
		scanner.add(serverPath + File.separator + "gamemodes");
		scanner.add(serverPath + File.separator + "npcmodes");
		scanner.add(serverPath + File.separator + "includes");

		File[] files = scanner.getFileList();

		Arrays.sort(files);

		for (File file : files)
		{
			BufferedReader bufferedReader = new BufferedReader(new FileReader(file));

			String line;
			int lineNumber = 0;
			while ((line = bufferedReader.readLine()) != null)
			{
				lineNumber++;
				int searchIndex = line.indexOf("// TODO");
				if (searchIndex != -1)
				{
					System.out.println(file.getAbsolutePath() + " (" + lineNumber + "): todo " + line.substring(searchIndex + 7).trim());
				}
			}
		}
	}
}
