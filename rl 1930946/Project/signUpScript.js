function checkBlank(){

	var Fname = document.getElementById('Fname');

	if(Fname.value == ""){
	
		alert("Please enter your first name");
		Fname.style.backgroundColor = "grey";
		Fname.style.borderColor = "yellow";
		Fname.focus();
		Fname.select();
		return false;
	}	
	
	var Lname = document.getElementById('Lname');
	if(Lname.value == ""){
	
		alert("Please enter last name");
		Lname.style.backgroundColor = "grey";
		Lname.style.borderColor = "yellow";
		Lname.focus();
		Lname.select();
		return false;
	}
	
	var bDay1 = document.getElementById('bDay1');
	var bDay2 = document.getElementById('bDay2');
	var bDay3 = document.getElementById('bDay3');
	
	if(bDay1.value == "" || bDay2.value == "" || bDay3.value == ""){
		
		alert("Please enter your FULL birthday");
		
			if(bDay1.value == "" ){
		
			bDay1.style.backgroundColor = "grey";
			bDay1.style.borderColor = "yellow";
			bDay1.focus();
			bDay1.select();
			return false;
			}
			
			
			if(bDay2.value == "" ){
				
			bDay2.style.backgroundColor = "grey";
			bDay2.style.borderColor = "yellow";
			bDay2.focus();
			bDay2.focus();
			return false;
			}
			
			if(bDay3.value == "" ){
				
	
		
			bDay3.style.backgroundColor = "grey";
			bDay3.style.borderColor = "yellow";
			bDay3.focus();
			bDay3.focus();
			return false;
			}
			
			
	}
	
	var street = document.getElementById('street');
	var city = document.getElementById('city');
	var state = document.getElementById('state');
	var zip = document.getElementById('zip');
	
	if(street.value == "" || city.value == "" || state.value == "" || zip.value == ""){
		
		alert("Please enter your FULL address");
		
			if(street.value == "" ){
			
			street.style.backgroundColor = "grey";
			street.style.borderColor = "yellow";
			street.focus();
			street.select();
			return false;
			}
			
			
			if(city.value == "" ){
	
			city.style.backgroundColor = "grey";
			city.style.borderColor = "yellow";
			city.focus();
			city.select();
			return false;
			}
			
			if(state.value == "" ){
	
			state.style.backgroundColor = "grey";
			state.style.borderColor = "yellow";
			state.focus();
			state.select();
			return false;
			}
			
			if(zip.value == "" ){
	
		
			zip.style.backgroundColor = "grey";
			zip.style.borderColor = "yellow";
			zip.focus();
			zip.select();
			return false;
			}
			
	}
	
	var phone = document.getElementById('phone');
	
	if(phone.value == ""){
		
		alert("Please enter a phone number ie 555-555-5555");
		phone.style.backgroundColor = "grey";
		phone.style.borderColor = "yellow";
		phone.focus();
		phone.select();
		return false;
	}
	
	var Fname2 = document.getElementById('Fname2');
	
	if(Fname2.value == ""){
		
		alert("Please enter an emergency contact first name");
		Fname2.style.backgroundColor = "grey";
		Fname2.style.borderColor = "yellow";
		Fname2.focus();
		Fname2.select();
		return false;
	}
	
	var Lname2 = document.getElementById('Lname2');
	
	if(Lname2.value == ""){
		
		alert("Please enter an emergency contact last name");
		Lname2.style.backgroundColor = "grey";
		Lname2.style.borderColor = "yellow";
		Lname2.focus();
		Lname2.select();
		return false;
	}	
	
}

function Fname_onchange(){

	var Fname = document.getElementById('Fname');
	var RegExpTxt = /^([a-zA-Z ]){2,30}$/;
	//First and Last Name with spaces at the beginning and end with at least one space between names
	//var RegExpTxt = /^\s*[A-Z][a-z]{1,14}\s+[A-Z][a-z]{1,19}\s*$/;

	if (!RegExpTxt.test(Fname.value)) {
    alert('Please provide a valid first name');
	Fname.style.backgroundColor = "gray";
	Fname.style.borderColor = "red";
    Fname.focus();
	Fname.select();
    return false;
	}
}

function Lname_onchange(){

	var Lname = document.getElementById('Lname');
	var RegExpTxt = /^([a-zA-Z ]){2,30}$/;

	if (!RegExpTxt.test(Lname.value)) {
    alert('Please provide a valid last name');
	Lname.style.backgroundColor = "gray";
	Lname.style.borderColor = "red";
    Lname.focus();
	Lname.select();
    return false;
	}
}


function Bday_onchange(){
	
	var bDay1 = document.getElementById('bDay1');
	var bDay2 = document.getElementById('bDay2');
	var bDay3 = document.getElementById('bDay3');

	if(isNaN(bDay1.value) == true || isNaN(bDay2.value) == true || isNaN(bDay3.value) == true  ){
		
		alert("Please enter a valid birth date");
		
		if(isNaN(bDay1.value) == true) {
		
		bDay1.style.backgroundColor = "gray";
		bDay1.style.borderColor = "red";
		bDay1.focus();
		bDay1.select();
		return false;
		}
		
		if(isNaN(bDay2.value) == true) {
		
		bDay2.style.backgroundColor = "gray";
		bDay2.style.borderColor = "red";
		bDay2.focus();
		bDay2.select();
		return false;
		}
		
		if(isNaN(bDay3.value) == true) {
		
		bDay3.style.backgroundColor = "gray";
		bDay3.style.borderColor = "red";
		bDay3.focus();
		bDay3.select();
		return false;
		}
	}
	
}


function street_onchange(){

	var street = document.getElementById('street');
	var RegExpStr = /^\s*\d{4,6}\s[a-zA-Z]{2,30}\s[a-zA-Z\.]{2,20}\s*$/;

	if (!RegExpStr.test(street.value)) {
    alert('Please provide a valid street address: ie 5555 Street Avenue');
	street.style.backgroundColor = "gray";
	street.style.borderColor = "red";
    street.focus();
	street.select();
    return false;
	}

}

function city_onchange(){

	var city = document.getElementById('city');
	var RegExpStr = /^\s*\d{4,6}\s[a-zA-Z]{2,30}\s[a-zA-Z\.]{2,20}\s*$/;
	//var RegExpTxt = /^([a-zA-Z ]){2,30}$/;

	if (!RegExpStr.test(city.value)) {
    alert('Please provide a valid city name');
	city.style.backgroundColor = "gray";
	city.style.borderColor = "red";
    city.focus();
	city.select();
    return false;
	}

}

function zip_onchange(){

	var zip = document.getElementById('zip');
	var RegExpZip = /^\s*[0-9]{5}([-][0-9]{4})?\s*$/;

	if (!RegExpZip.test(zip.value)) {
    alert('Please provide a valid zip number');
	zip.style.backgroundColor = "gray";
	zip.style.borderColor = "red";
    zip.focus();
	zip.select();
    return false;
	}

}


function contactFname_onchange(){

	var Fname2 = document.getElementById('Fname2');
	var RegExpTxt = /^([a-zA-Z ]){2,30}$/;

	if (!RegExpTxt.test(Fname2.value)) {
    alert('Please provide a valid contact first name ');
	Fname2.style.backgroundColor = "gray";
	Fname2.style.borderColor = "red";
    Fname2.focus();
	Fname2.select();
    return false;
	}
}


function contactLname_onchange(){

	var Lname2 = document.getElementById('Lname2');
	var RegExpTxt = /^([a-zA-Z ]){2,30}$/;

	if (!RegExpTxt.test(Fname2.value)) {
    alert('Please provide a valid contact first name ');
	Lname2.style.backgroundColor = "gray";
	Lname2.style.borderColor = "red";
    Lname2.focus();
	Lname2.select();
    return false;
	}
}


function phone_onchange(){

	var phone = document.getElementById('phone');
	var RegExpPhone = /^\s*1?\-?\d{3}\-\d{3}\-\d{4}\s*$/;

	if (!RegExpPhone.test(phone.value)) {
    alert('Please provide a valid phone number of the format: 555-555-5555');
	phone.style.backgroundColor = "gray";
	phone.style.borderColor = "red";
    phone.focus();
	phone.select();
    return false;
	}

}
