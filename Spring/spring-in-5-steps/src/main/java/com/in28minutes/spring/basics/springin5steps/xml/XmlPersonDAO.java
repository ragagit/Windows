/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.basics.springin5steps.xml;

//import com.in28minutes.spring.basics.springin5steps.xml.XMLJdbcConnection;
//import org.springframework.beans.factory.annotation.Autowired;
//import org.springframework.stereotype.Component;

/**
 *
 * @author Administrator
 */

public class XmlPersonDAO {
     
XmlJdbcConnection xmlJdbcConnection;

    public XmlJdbcConnection getXmlJdbcConnection() {
        return xmlJdbcConnection;
    }

    public void setXmlJdbcConnection(XmlJdbcConnection xmlJdbcConnection) {
        this.xmlJdbcConnection = xmlJdbcConnection;
    }
    
}
