// JavaScript Document

	/*Portions of this code have been borrowed from 
	  Class projects and other students Javascript
	  I still do not fully understand how this code
	  works. However I was able to implement it into
	  my own work using examples from other students
	  source code. Comments have been ommited from
	  original user and my own have been inserted
	  to help me better understand what the code does
	  	-Andrew*/

//This function separates the data in the form into name/value pairs.

function getSubmittedForm () {
	//First, an object is created to store the parameters.
	//Parameters will be allocated into an array
	var formObj = new Object ();
	//This separates the form items from the entire page and allocates them into an array (I believe)
	//The .split returns the array
	var url = location.href;
	var parameterslist = url.split("?");
	//Second split
	var parameters = parameterslist[1].split("&");
	//This for loop loops through the name-value pairs or each array and returns them into an object.
	for (var i = 0; i < parameters.length; i ++){
		var map = parameters[i].split("=");
		var property = map[0];
		var value = map[1];
		
		formObj[property] = value;
	}
	return formObj;
}



//Displays the name-value pairs with a for loop.

function displaySubmittedForm (formObj) {
	for (var propertyName in formObj){
		document.write(propertyName + " = " + formObj[propertyName] + "<br />");
	}
}
