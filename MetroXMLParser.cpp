#include "iostream"
#include "MetroXMLParser.h"
#include "tinyxml/tinyxml.h"

MetroXMLParser::MetroXMLParser(const std::string &filename) : filename(filename) {
    parse();
}

MetroXMLParser::~MetroXMLParser() {}

bool MetroXMLParser::parse() {
    TiXmlDocument doc(filename.c_str());
    if (!doc.LoadFile()) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return false;
    }

    TiXmlElement* root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return false;
    }

    TiXmlElement* elem = root->FirstChildElement();
    while (elem->NextSiblingElement()) {
        std::string elemName = elem->Value();
        if (elemName == "STATION") {
            std::string naam = elem->FirstChildElement("naam")->GetText();
            std::cout << naam << std::endl;
        }


        elem = elem->NextSiblingElement();
    }




    return true;
}


