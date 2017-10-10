/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function sayHelloFromLib(){
    alert("Hello from JS Library");
}

// Java Script has three primitive types 
// Number, String, Boolean plus null, undefined and object
// You use var to declare a variable. This will take any value
// var str = "Something"
// var num = 57
// 
// Global variables are insode <script> </script> but outside function
// Local variables are inside function
//
// Operands + - / % ++ -- == >= <= && || ! & | << >> ~ += -= *= %= ?:
// typeof  i.e. result = (typeof a == "string" ? "A is String" : "A is Numeric");
// return "Number" "String" "Boolean" "Object" "Function" "Undefined"
// Type "number" "string" "boolean" "object" "function" "undefine"
// document.write(result) would return "String"
//
// if else

function ifelseexample(){
    var age = 23;
    
    document.write("<br/>");
    
    if( age > 18 ){
        document.write("<b>Qualifies for driving</b>");
        document.write("<br/>");
    }          
    else{
        document.write("<b>Does not qualify for driving</b>");
    }
}

// switch

function switchexample(){
            var grade='A';
            
            document.write("Entering switch block<br />");
            switch (grade)
            {
               case 'A': document.write("Good job<br />");
               break;
            
               case 'B': document.write("Pretty good<br />");
               break;
            
               case 'C': document.write("Passed<br />");
               break;
            
               case 'D': document.write("Not so good<br />");
               break;
            
               case 'F': document.write("Failed<br />");
               break;
            
               default:  document.write("Unknown grade<br />");
            }
            document.write("Exiting switch block<br/>");
}

//while do-while
function whileExample(){
    
            var count = 0;
            document.write("Starting while Loop <br />");
         
            while (count < 3){
               document.write("Current Count : " + count + "<br />");
               count++;
            }
         
            document.write("Loop stopped! <br />");
}

//for loop

function forExample(){
                var count;
            document.write("Starting for Loop" + "<br />");
         
            for(count = 0; count < 3; count++){
               document.write("Current Count : " + count );
               document.write("<br />");
            }
         
            document.write("Loop stopped! <br />");
}

// for in

function forinExample(){
               var aProperty;
            document.write("Navigator Object Properties<br /> ");
         
            for (aProperty in navigator) {
               document.write(aProperty);
               document.write("<br />");
            }
            document.write ("Exiting from the loop! <br/>");
}

// break continue label :

function labelExample(){
            document.write("Entering the loop!<br /> ");
            outerloop: // This is the label name
         
            for (var i = 0; i < 5; i++)
            {
               document.write("Outerloop: " + i + "<br />");
               innerloop:
               for (var j = 0; j < 5; j++)
               {
                  if (j > 3 ) break ; // Quit the innermost loop
                  if (i == 2) break innerloop; // Do the same thing
                  if (i == 4) break outerloop; // Quit the outer loop
                  document.write("Innerloop: " + j + " <br />");
               }
            }
         
            document.write("Exiting the loop!<br /> "); 
}

// return
         function concatenate(first, last)
         {
            var full;
            full = first + last;
            return full;
         }
         
         function secondFunction()
         {
            var result;
            result = concatenate('Zara', 'Ali');
            document.write (result );
         }
         
//Events 
//onclick onsubmit onmouseover onmouseout
            function validation() {
               document.write("Form validated");
               return true;
            }
            function over() {
               alert("Mouse Over");
            }
            
            function out() {
               alert("Mouse Out");
            }    
// Cookies            
/*
  Cookies are a plain text data record of 5 variable-length fields −
  Expires − The date the cookie will expire. If this is blank, the cookie will expire when the visitor quits the browser.
  Domain − The domain name of your site.
  Path − The path to the directory or web page that set the cookie. This may be blank if you want to retrieve the cookie from any directory or page.
  Secure − If this field contains the word "secure", then the cookie may only be retrieved with a secure server. If this field is blank, no such restriction exists.
  Name=Value − Cookies are set and retrieved in the form of key-value pairs
  document.cookie = "key1=value1;key2=value2;expires=date";                      
                        
 */
            function WriteCookie()
            {
                //setting expiry date
               var now = new Date();
               now.setMonth( now.getMonth() + 1 );
               
               if( document.myform.customer.value == "" ){
                  alert("Enter some value!");
                  return;
               }
               cookievalue= escape(document.myform.customer.value) + ";";
               document.cookie="name=" + cookievalue;
               document.write ("Setting Cookies : " + "name=" + cookievalue );
            }
            
             function ReadCookie()
            {
               var allcookies = document.cookie;
               document.write ("All Cookies : " + allcookies );
               
               // Get all the cookies pairs in an array
               cookiearray = allcookies.split(';');
               
               // Now take key value pair out of this array
               for(var i=0; i<cookiearray.length; i++){
                  name = cookiearray[i].split('=')[0];
                  value = cookiearray[i].split('=')[1];
                  document.write ("Key is : " + name + " and Value is : " + value);
               }
            } 
            
            //To delete a cookie you just need to set the expiry date to a time in the past.
            //   var now = new Date();
            //   now.setMonth( now.getMonth() + 1 );
            
// Page redirection

           function Redirect() {
            var browsername=navigator.appName;
                if( browsername == "Netscape" )
                {
                    window.location="http://www.location.com/ns.htm";
                }

                window.location="http://www.tutorialspoint.com";
            }
            
         function RedirectMsg(){
             
                document.write("You will be redirected to main page in 10 sec.");
                setTimeout('Redirect()', 10000);
         }
    
// Dialog Boxes
            function Warn() {
               alert ("This is a warning message!");
               document.write ("This is a warning message!");
            }
            function getConfirmation(){
               var retVal = confirm("Do you want to continue ?");
               if( retVal == true ){
                  document.write ("User wants to continue!");
                  return true;
               }
               else{
                  document.write ("User does not want to continue!");
                  return false;
               }
            }
            function getValue(){
               var retVal = prompt("Enter your name : ", "your name here");
               document.write("You have entered : " + retVal);
            }
            
//Print
    function printMypage(){
        window.print();
    }
    
//Objects

// JavaScript is a object oreinted programming, Encapsulation, Aggregation, Inheritance and Polymorfism
// Objects has methids, use new and this to refer to the object itself
// All objects are descendent of Object

function creatObject(){
           var book = new Object();   // Create the object
         book.subject = "Perl"; // Assign properties to the object
         book.author  = "Mohtashim";
         
         return book;
}

function sayHi(){
    document.write("<br />");
    document.writeln("Hi from object method");
}

function createObject2(){
    this.subject = "Perl";
    this.author = "Mohtashim";
    this.sayHi = sayHi;
}
// We can use with to avoid to refernce the object within the block
function createObject3(){
    with(this){
        title = "Book";
        type = "fiction";
        pages = "200";
    }
}

//JavaScript native objects Number, String, Array, Boolean, Date, Math, RegExp

// Error handling
function errorHandlingExample(){

               var a = 100;
               
               try {
                  alert("Value of variable a is : " + a );
               }
               
               catch ( e ) {
                  alert("Error: " + e.description );
               }
               
               finally {
                  alert("Finally block will always execute!" );
               }         
}
//throw
            function myFunc()
            {
               var a = 100;
               var b = 0;
               
               try{
                  if ( b == 0 ){
                     throw( "Divide by zero error." ); 
                  }
                  
                  else
                  {
                     var c = a / b;
                  }
               }
               
               catch ( e ) {
                  alert("Error: " + e );
               }
            }
            
// Validation
function validate()
      {
      
         if( document.myForm.Name.value == "" )
         {
            alert( "Please provide your name!" );
            document.myForm.Name.focus() ;
            return false;
         }
         
         if( document.myForm.EMail.value == "" )
         {
            alert( "Please provide your Email!" );
            document.myForm.EMail.focus() ;
            return false;
         }
         
         if( document.myForm.Zip.value == "" ||
         isNaN( document.myForm.Zip.value ) ||
         document.myForm.Zip.value.length != 5 )
         {
            alert( "Please provide a zip in the format #####." );
            document.myForm.Zip.focus() ;
            return false;
         }
         
         if( document.myForm.Country.value == "-1" )
         {
            alert( "Please provide your country!" );
            return false;
         }
         return( true );
      }
      
function validateEmail()
      {
         var emailID = document.myForm.EMail.value;
         atpos = emailID.indexOf("@");
         dotpos = emailID.lastIndexOf(".");
         
         if (atpos < 1 || ( dotpos - atpos < 2 )) 
         {
            alert("Please enter correct email ID")
            document.myForm.EMail.focus() ;
            return false;
         }
         return( true );
      }
      
            var imgObj = null;
            var animate ;
            
            function init(){
               imgObj = document.getElementById('myImage');
               imgObj.style.position= 'relative'; 
               imgObj.style.left = '0px'; 
            }
            
            function moveRight(){
               imgObj.style.left = parseInt(imgObj.style.left) + 10 + 'px';
               animate = setTimeout(moveRight,20); // call moveRight in 20msec
            }
            
            function stop(){
               clearTimeout(animate);
               imgObj.style.left = '0px'; 
            }
            
            var image1, image2;
            function loadImgs(){
              if(document.images){
               image1 = new Image(); // Preload an image
               image1.src = "./images/bird_icon.gif";
               image2 = new Image(); // Preload second image
               image2.src = "./images/brand_logo.gif";
             }
         }
           
    
    // Use www.jslint.com to validate your JavaScript code.
    
    function browserType(){
                    var userAgent   = navigator.userAgent;
            var opera       = (userAgent.indexOf('Opera') != -1);
            var ie          = (userAgent.indexOf('MSIE') != -1);
            var gecko       = (userAgent.indexOf('Gecko') != -1);
            var netscape    = (userAgent.indexOf('Mozilla') != -1);
            var version     = navigator.appVersion;
            
            if (opera){
               document.write("Opera based browser");
               // Keep your opera specific URL here.
            }
            
            else if (gecko){
               document.write("Mozilla based browser");
               // Keep your gecko specific URL here.
            }
            
            else if (ie){
               document.write("IE based browser");
               // Keep your IE specific URL here.
            }
            
            else if (netscape){
               document.write("Netscape based browser");
               // Keep your Netscape specific URL here.
            }
            
            else{
               document.write("Unknown browser");
            }
            // You can include version to along with any above condition.
            document.write("<br /> Browser version info : " + version );
    }
      