// JavaScript Document

//Sign up form
//Form Validation Script

//These functions will validate the entered form data
//Borrowed from Class Examples.  Edited to fit this project.

	//Name Validation
	//Validates any first or last name field
	//Checks for a capital first letter and lowercase letters following it.
				function validateFName(){
                    var x=document.forms["SignUp"]["firstName"].value;
                    var re = new RegExp(/^\s*[A-Z][a-z]{2,10}\s*$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter First Name.");
                        return false;
                    }else{
                        return true;
                    }
                }
	//Validates Middile Initial.
				function validateMi(){
                    var x=document.forms["SignUp"]["mi"].value;
                    var re = new RegExp(/^\s*[A-Z]{1}\s*$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter Middle Initial.");
                        return false;
                    }else{
                        return true;
                    }
                }
	//Validates last name field
	//Same function as first name
                function validateLName(){
                    var x=document.forms["SignUp"]["lastName"].value;
                    var re = new RegExp(/^\s*[A-Z][a-z]{2,10}\s*$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter Last Name.");
                        return false;
                    }else{
                        return true;
                    }
                }
				
				//Address Validation
	//Validates Address
	//Checks for number and street.
				function validateAddress(){
                    var x=document.forms["SignUp"]["street"].value;
                    var re = new RegExp(/^\s*\d{1,5}\s[A-Z][a-z]{2,10}\s[A-Z][a-z]{1,10}\s*$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter a Valid Address.");
                        return false;
                    }else{
                        return true;
                    }
                }
	//Validates City
				function validateCity(){
                    var x=document.forms["SignUp"]["city"].value;
                    var re = new RegExp(/^\s*[A-Z][a-z]{2,15}\s*$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter City of Residence.");
                        return false;
                    }else{
                        return true;
                    }
                }
	//Validates Zip Code
				function validateZip(){
                    var x=document.forms["SignUp"]["zip"].value;
                    var re = new RegExp(/^\s*[0-9]{5}\s*$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter Zip Code.");
                        return false;
                    }else{
                        return true;
                    }
                }
	//Validate Phone Number
				function validateTel(){
                    var x=document.forms["SignUp"]["phone"].value;
                    var re = new RegExp(/^\s*[0-9]{3}\-[0-9]{3}\-[0-9]{4}\s*$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter Phone Number.");
                        return false;
                    }else{
                        return true;
                    }
                }
	//Validates E-mail field
	//Checks that the e-mail address will contain the following
		/*any letters or numbers including characters such as "_", "+", and "-".
		a possilb period in the address name followed by the same match as above
		a single @ symbol
		a url containing a string separated by at least one dot but possibly two.*/
	//This should include MOST valid e-mail addresses.
	//Source of regular expression http://www.markussipila.info/pub/emailvalidator.php
				function validateEmail(){
					var x=document.forms["SignUp"]["e-mail"].value;
                    var re = new RegExp(/^[a-z0-9_\+-]+(\.[a-z0-9_\+-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*\.([a-z]{2,4})$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter E-mail Address.");
                        return false;
                    }else{
                        return true;
                    }
				}
				
				//Emegercency Contact Validation
	//First Name
				function validateEmFName(){
                    var x=document.forms["SignUp"]["EfirstName"].value;
                    var re = new RegExp(/^\s*[A-Z][a-z]{2,10}\s*$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter Emergency Contact First Name.");
                        return false;
                    }else{
                        return true;
                    }
                }
	//Last Name
				function validateEmLName(){
                    var x=document.forms["SignUp"]["ElastName"].value;
                    var re = new RegExp(/^\s*[A-Z][a-z]{2,10}\s*$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter Emergency Contact Last Name.");
                        return false;
                    }else{
                        return true;
                    }
                }
	//Validate Phone Number
				function validateETel(){
                    var x=document.forms["SignUp"]["ephone"].value;
                    var re = new RegExp(/^\s*[0-9]{3}\-[0-9]{3}\-[0-9]{4}\s*$/);
                    var m = re.exec(x);
                    if (m==null){
                        alert("Please Enter Emergency Contact Phone Number.");
                        return false;
                    }else{
                        return true;
                    }
                }
	//Final validation is summarized into one function with if statements
                function validateForm(){
                    if(!validateFName())return false;
					if(!validateMi())return false;
                    if(!validateLName())return false;
					if(!validateAddress())return false;
					if(!validateCity())return false;
					if(!validateZip())return false;
					if(!validateEmail())return false;
					if(!validateTel())return false;
					if(!validateEmFName())return false;
					if(!validateEmLName())return false;
					if(!validateETel())return false;
                    return true;
                }