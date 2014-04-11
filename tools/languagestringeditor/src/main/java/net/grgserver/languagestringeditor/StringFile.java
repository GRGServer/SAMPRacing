package net.grgserver.languagestringeditor;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import javax.swing.table.DefaultTableModel;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class StringFile
{
	private File file;
	private StringList stringList;
	private List<String> languages;

	public StringFile(StringList stringList)
	{
		this.file = new File(Main.getServerPath() + File.separator + "scriptfiles" + File.separator + "languagestrings.xml");

		this.stringList = stringList;

		this.load();
	}

	public boolean load()
	{
		try
		{
			DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();

			DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();

			Document document = documentBuilder.parse(this.file);

			Element rootElement = document.getDocumentElement();

			DefaultTableModel tableModel = (DefaultTableModel) this.stringList.getModel();

			tableModel.setColumnCount(0);// Remove all columns
			tableModel.setRowCount(0);// Remove all rows

			this.languages = new ArrayList<>();

			tableModel.addColumn("ID");

			NodeList languageNodes = rootElement.getElementsByTagName("language");
			for (int nodeIndex = 0; nodeIndex < languageNodes.getLength(); nodeIndex++)
			{
				Node languageNode = languageNodes.item(nodeIndex);

				NamedNodeMap attributes = languageNode.getAttributes();

				this.languages.add(attributes.getNamedItem("name").getNodeValue());

				tableModel.addColumn(languageNode.getTextContent());
			}

			tableModel.addColumn("Ignore unused");
			tableModel.addColumn("References");

			NodeList stringNodes = rootElement.getElementsByTagName("string");
			for (int stringNodeIndex = 0; stringNodeIndex < stringNodes.getLength(); stringNodeIndex++)
			{
				Node stringNode = stringNodes.item(stringNodeIndex);

				NamedNodeMap attributes = stringNode.getAttributes();

				int id = new Integer(attributes.getNamedItem("id").getNodeValue());
				boolean ignoreUnused = attributes.getNamedItem("ignoreUnused") != null;

				List<Object> rowData = new ArrayList<>();

				rowData.add(id);

				NodeList translationNodes = stringNode.getChildNodes();
				for (String language : this.languages)
				{
					String string = "";

					for (int translationNodeIndex = 0; translationNodeIndex < translationNodes.getLength(); translationNodeIndex++)
					{
						Node translationNode = translationNodes.item(translationNodeIndex);

						if (translationNode.getNodeName().equals(language))
						{
							string = translationNode.getTextContent().trim();
							break;
						}
					}

					rowData.add(string);
				}

				rowData.add(ignoreUnused);

				tableModel.addRow(rowData.toArray());
			}

			this.stringList.resetChanged();

			return true;
		}
		catch (Exception exception)
		{
			exception.printStackTrace();
			return false;
		}
	}

	public boolean save()
	{
		try
		{
			DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();

			DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();

			Document document = documentBuilder.newDocument();

			Element rootElement = document.createElement("languagestrings");
			document.appendChild(rootElement);

			for (int languageIndex = 0; languageIndex < this.languages.size(); languageIndex++)
			{
				Element languageNode = document.createElement("language");
				rootElement.appendChild(languageNode);

				languageNode.setAttribute("name", this.languages.get(languageIndex));

				languageNode.appendChild(document.createTextNode(this.stringList.getColumnName(languageIndex + 1)));
			}

			for (int row = 0; row < this.stringList.getRowCount(); row++)
			{
				Element stringNode = document.createElement("string");
				rootElement.appendChild(stringNode);

				stringNode.setAttribute("id", Integer.toString((Integer) this.stringList.getValueAt(row, 0)));

				if ((boolean) this.stringList.getValueAt(row, this.stringList.getColumnIndexByType(StringList.ColumnTypes.IGNORE_UNUSED)))
				{
					stringNode.setAttribute("ignoreUnused", "1");
				}

				for (int languageIndex = 0; languageIndex < this.languages.size(); languageIndex++)
				{
					Element translationNode = document.createElement(this.languages.get(languageIndex));
					translationNode.appendChild(document.createTextNode(((String) this.stringList.getValueAt(row, languageIndex + this.stringList.getColumnIndexByType(StringList.ColumnTypes.FIRST_LANGUAGE)))));
					stringNode.appendChild(translationNode);
				}
			}

			TransformerFactory transformerFactory = TransformerFactory.newInstance();
			Transformer transformer = transformerFactory.newTransformer();

			transformer.setOutputProperty(OutputKeys.ENCODING, "ISO-8859-1");
			transformer.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "no");
			transformer.setOutputProperty(OutputKeys.INDENT, "yes");
			transformer.setOutputProperty("{http://xml.apache.org/xslt}indent-amount", "2");

			DOMSource domSource = new DOMSource(document);

			StreamResult streamResult = new StreamResult(this.file);

			transformer.transform(domSource, streamResult);

			return true;
		}
		catch (Exception exception)
		{
			exception.printStackTrace();
			return false;
		}
	}
}
