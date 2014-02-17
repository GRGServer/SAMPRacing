enum e_XML_NODE_TYPE
{
	e_XML_NODE_DOCUMENT,
	e_XML_NODE_ELEMENT,
	e_XML_NODE_COMMENT,
	e_XML_NODE_UNKNOWN,
	e_XML_NODE_TEXT,
	e_XML_NODE_DECLARATION,
	e_XML_NODE_TYPECOUNT
}


/**
 * <summary>
 *	Creates a new document.
 * </summary>
 *
 * <param name="filename">
 *	The file name that will be used on saving.
 * </param>
 *
 * <param name="version">
 *	The XML version (optional, defaults to "1.0").
 * </param>
 *
 * <param name="encoding">
 *	Character encoding which appears in XML declaration.
 * </param>
 *
 * <returns>
 *	Handle to document tree root node.
 * </returns>
 */

native XMLNode:XML_CreateDocument(const filename[], const version[] = "1.0", const encoding[] = "ISO-8859-1");


/**
 * <summary>
 *	Loads a document from a file.
 * </summary>
 *
 * <param name="filename">
 *	Path to the file.
 * </param>
 *
 * <returns>
 *	Handle to the document tree root node.
 * </returns>
 *
 * <see>XML_SaveDocument</see>
 * <see>XML_UnloadDocument</see>
 */

native XMLNode:XML_LoadDocument(const filename[]);


/**
 * <summary>
 *	Saves a document to a file.
 * </summary>
 *
 * <param name="doc">
 *	Handle to the document root.
 * </param>
 *
 * <param name="filename">
 *	The file name (optional).
 * </param>
 *
 * <returns>
 *	<item>true on success</item>
 *	<item>false if failed</item>
 * </returns>
 *
 * <see>XML_LoadDocument</see>
 * <see>XML_UnloadDocument</see>
 */

native bool:XML_SaveDocument(XMLNode:doc, const filename[] = "");


/**
 * <summary>
 *	Fully destroys a document (i.e. including all of its nodes) and frees memory.
 * </summary>
 *
 * <param name="doc">
 *	The document to be unloaded.
 * </param>
 *
 * <see>XML_LoadDocument</see>
 * <see>XML_SaveDocument</see>
 */

native XML_UnloadDocument(XMLNode:doc);


/**
 * <summary>
 *	Creates a new node and optionally makes it to be a child of another one.
 * </summary>
 *
 * <param name="parent">
 *	Parent node, use 0 to specify no parent.
 * </param>
 *
 * <param name="value">
 *	<title>The value of the node.</title>
 *	<item name="Document">Filename of the xml file</item>
 *	<item name="Element">Name of the element</item>
 *	<item name="Comment">The comment text</item>
 *	<item name="Unknown">The tag contents</item>
 *	<item name="Text">The text string</item>
 * </param>
 *
 * <param name="type">
 *	<title>The type of the node.</title>
 *	<item name="e_XML_NODE_ELEMENT"></item>
 *	<item name="e_XML_NODE_COMMENT"></item>
 *	<item name="e_XML_NODE_TEXT"></item>
 * </param>
 *
 * <returns>
 *	<item>The handle of the created node</item>
 *	<item>0 if failed</item>
 * </returns>
 *
 * <see>XML_DestroyNode</see>
 */

native XMLNode:XML_CreateNode(XMLNode:parent, const value[], e_XML_NODE_TYPE:type = e_XML_NODE_ELEMENT);


/**
 * <summary>
 *	Deletes a specific child of a node and replaces it with a new one.
 * </summary>
 *
 * <param name="parent">
 *	The parent node.
 * </param>
 *
 * <param name="oldChild">
 *	The child to be replaced.
 * </param>
 *
 * <param name="newChild">
 *	The new child.
 * </param>
 *
 * <returns>
 *	<item>true on success</item>
 *	<item>false if failed</item>
 * </returns>
 */

//native bool:XML_ReplaceChild(XMLNode:parent, XMLNode:oldChild, XMLNode:newChild);


/**
 * <summary>
 *	Removes a specific child of a node and deletes it from memory.
 * </summary>
 *
 * <param name="parent">
 *	The parent node.
 * </param>
 *
 * <param name="child">
 *	The child to be removed.
 * </param>
 *
 * <returns>
 *	<item>true on success</item>
 *	<item>false if failed</item>
 * </returns>
 */

native bool:XML_RemoveChild(XMLNode:parent, XMLNode:child);


/**
 * <summary>
 *	Deletes selected node from memory.
 * </summary>
 *
 * <param name="node">
 *	The node to be destroyed.
 * </param>
 *
 * <see>XML_CreateNode</see>
 */

native XML_DestroyNode(XMLNode:node);


/**
 * <summary>
 *	Finds first child of a selected node by its value.
 * </summary>
 *
 * <param name="node">
 *	The node to get the child of.
 * </param>
 *
 * <param name="value">
 *	The value to be searched for (optional).
 * </param>
 *
 * <returns>
 *	<item>true on success</item>
 *	<item>false if failed</item>
 * </returns>
 *
 * <see>XML_GetLastChild</see>
 */

native XMLNode:XML_GetFirstChild(XMLNode:node, const value[] = "");


/**
 * <summary>
 *	Finds first child of a selected node by its value.
 * </summary>
 *
 * <param name="node">
 *	The node to get the child of.
 * </param>
 *
 * <param name="value">
 *	The value to be searched for (optional).
 * </param>
 *
 * <returns>
 *	<item>The handle of the first child</item>
 *	<item>0 if failed</item>
 * </returns>
 *
 * <see>XML_GetFirstChild</see>
 */

native XMLNode:XML_GetLastChild(XMLNode:node, const value[] = "");


/**
 * <summary>
 *	Finds next sibling of a selected node by its value.
 * </summary>
 *
 * <param name="node">
 *	The node to find sibling of.
 * </param>
 *
 * <param name="value">
 *	The value to be searched for (optional).
 * </param>
 *
 * <returns>
 *	<item>The handle of the last child</item>
 *	<item>0 if failed</item>
 * </returns>
 *
 * <see>XML_GetPreviousSibling</see>
 */

native XMLNode:XML_GetNextSibling(XMLNode:node, const value[] = "");


/**
 * <summary>
 *	Finds previous sibling of a selected node by its value.
 * </summary>
 *
 * <param name="node">
 *	The node to find sibling of.
 * </param>
 *
 * <param name="value">
 *	The value to be searched for (optional).
 * </param>
 *
 * <returns>
 *	<item>The handle of the next sibling</item>
 *	<item>0 if failed</item>
 * </returns>
 *
 * <see>XML_GetNextSibling</see>
 */

native XMLNode:XML_GetPreviousSibling(XMLNode:node, const value[] = "");


/** Returns node parent.
 *
 * <param name="node">
 *	The node.
 * </param>
 *
 * <returns>
 *	<item>The handle of the previous sibling</item>
 *	<item>0 if failed</item>
 * </returns>
 */

native XMLNode:XML_GetParent(XMLNode:node);


/**
 * <summary>
 *	Gets node value.
 * </summary>
 *
 * <param name="node">
 *	The node to get value of.
 * </param>
 *
 * <param name="value">
 *	An array which will hold the value.
 * </param>
 *
 * <param name="maxlen">
 *	Maximum value length.
 * </param>
 *
 * <see>XML_SetValue</see>
 */

native XML_GetValue(XMLNode:node, value[], maxlen = sizeof(value));


/**
 * <summary>
 *	Sets node value.
 * </summary>
 *
 * <param name="node">
 *	The node to set value of.
 * </param>
 *
 * <param name="value">
 *	<title>The value to be set.</title>
 *	<item name="e_XML_NODE_DOCUMENT">Filename of the xml file</item>
 *	<item name="e_XML_NODE_ELEMENT">Name of the element</item>
 *	<item name="e_XML_NODE_COMMENT">The comment text</item>
 *	<item name="e_XML_NODE_UNKNOWN">The tag contents</item>
 *	<item name="e_XML_NODE_TEXT">The text string</item>
 * </param>
 *
 * <see>XML_GetValue</see>
 */

native XML_SetValue(XMLNode:node, const value[]);


/**
 * <summary>
 *	Gets element attribute value.
 * </summary>
 *
 * <param name="element">
 *	The node to get attribute of (it should be an element node).
 * </param>
 *
 * <param name="name">
 *	Attribute name.
 * </param>
 *
 * <param name="value">
 *	Attribute value will be copied here.
 * </param>
 *
 * <param name="maxlen">
 *	Maximum value length.
 * </param>
 *
 * <see>XML_SetAttribute</see>
 * <see>XML_RemoveAttribute</see>
 */

native XML_GetAttribute(XMLNode:element, const name[], value[], maxlen = sizeof(value));


/**
 * <summary>
 *	Sets element attribute value.
 * </summary>
 *
 * <param name="element">
 *	The node to set attribute of (it should be an element node).
 * </param>
 *
 * <param name="name">
 *	Attribute name.
 * </param>
 *
 * <param name="value">
 *	Attribute value.
 * </param>
 *
 * <see>XML_GetAttribute</see>
 * <see>XML_RemoveAttribute</see>
 */

native XML_SetAttribute(XMLNode:element, const name[], const value[]);


/**
 * <summary>
 *	Removes selected attribute of an element.
 * </summary>
 *
 * <param name="element">
 *	The node (should be an element node).
 * </param>
 *
 * <param name="name">
 *	Attribute name.
 * </param>
 *
 * <see>XML_GetAttribute</see>
 * <see>XML_SetAttribute</see>
 */

native XML_RemoveAttribute(XMLNode:element, const name[]);


/**
 * <summary>
 *	Gets node type.
 * </summary>
 *
 * <param name="node">
 *	The node.
 * </param>
 *
 * <returns>
 *	The type of the specified node.
 * </returns>
 */

native e_XML_NODE_TYPE:XML_GetNodeType(XMLNode:node);


/**
 * <summary>
 *	Computes an integer XPath expression.
 * </summary>
 *
 * <param name="root">
 *	Handle to a source tree root.
 * </param>
 *
 * <param name="xpath">
 *	The XPath expression.
 * </param>
 *
 * <returns>
 *	Expression value.
 * </returns>
 */

native XML_GetXPathInt(XMLNode:root, const xpath[]);

/**
 * <summary>
 *	Computes a boolean XPath expression.
 * </summary>
 *
 * <param name="root">
 *	Handle to a source tree root.
 * </param>
 *
 * <param name="xpath">
 *	The XPath expression.
 * </param>
 *
 * <returns>
 *	Expression value.
 * </returns>
 */

native bool:XML_GetXPathBool(XMLNode:root, const xpath[]);


/**
 * <summary>
 *	Computes a float XPath expression.
 * </summary>
 *
 * <param name="root">
 *	Handle to a source tree root.
 * </param>
 *
 * <param name="xpath">
 *	The XPath expression.
 * </param>
 *
 * <returns>
 *	Expression value.
 * </returns>
 */

native Float:XML_GetXPathFloat(XMLNode:root, const xpath[]);


/**
 * <summary>
 *	Computes a string XPath expression.
 * </summary>
 *
 * <param name="root">
 *	Handle to a source tree root.
 * </param>
 *
 * <param name="xpath">
 *	The XPath expression.
 * </param>
 *
 * <returns>
 *	Expression value.
 * </returns>
 */

native XML_GetXPathString(XMLNode:root, const xpath[], result[], maxlen = sizeof(result));

/**
 * <summary>
 *	Computes a node XPath expression.
 * </summary>
 *
 * <param name="root">
 *	Handle to a source tree root.
 * </param>
 *
 * <param name="xpath">
 *	The XPath expression.
 * </param>
 *
 * <returns>
 *	Expression value.
 * </returns>
 */

native XMLNode:XML_GetXPathNode(XMLNode:root, const xpath[]);


/**
 * <summary>
 *	Computes an attribute XPath expression.
 * </summary>
 *
 * <param name="root">
 *	Handle to a source tree root.
 * </param>
 *
 * <param name="xpath">
 *	The XPath expression.
 * </param>
 *
 * <returns>
 *	Expression value.
 * </returns>
 */

native XMLAttr:XML_GetXPathAttribute(XMLNode:root, const xpath[]);
