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