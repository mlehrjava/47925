// JavaScript Document

//  --- First get the form info to be written to a cookie ---
function getFormInfo(url){    				//Get the info from the url
	var info=url.split("?");  				//Split information at the "?"
	var nameValuePairs=info[1].split("&");	//2nd split creates pairs of items to be split
	var obj=new Object();					//Map the name/value pairs to an Object
	for(var i=0;i<nameValuePairs.length-1;i++){
		var map=nameValuePairs[i].split("=");
		var name=map[0];
		var value=map[1];
		obj[name]=value;
	}
	return obj; //Return the object for use later
}

//  --- Write the form information into a cookie ---
	//Write the function to set a cookie first
function setCookie(name, value, secondsToLive) {
    var cookie = name + "=" + encodeURIComponent(value);
    if (typeof daysToLive === "number") 
        cookie += "; max-age=" + (daysToLive);
    document.cookie = cookie;
}
    var $_GET=getFormInfo(location.href);	//Place into the $_GET object
	var str=JSON.stringify($_GET);	//Test JSON to stringify
	var obj=JSON.parse(str);		//and parse back
	var username = prompt("Re-enter username to complete registration:");	//Cookie class
	var seconds=60*60*24*365.25; //All cookies will survive for one year.
	setCookie(username, str, seconds);	//Set the cookie by calling the function

//  --- Function to retrieve all cookies ---
// Return the document's cookies as an object of name/value pairs.
// Remember that cookie values are encoded with encodeURIComponent(line 20).
function getCookies() {
    var cookies = {};           // The object we will return
    var all = document.cookie;  // Get all cookies in one big string
    if (all === "")             // If the property is the empty string
        return cookies;         // return an empty object
    var list = all.split("; "); // Split into individual name=value pairs
    for(var i = 0; i < list.length; i++) {  // For each cookie
        var cookie = list[i];
        var p = cookie.indexOf("=");        // Find the first = sign
        var name = cookie.substring(0,p);   // Get cookie name
        var value = cookie.substring(p+1);  // Get cookie value
        value = decodeURIComponent(value);  // Decode the value
        cookies[name] = value;              // Store name and value in object
    }
    return cookies;
}

//  --- Functin to retrieve Specific cookie by name ---
		// >-From W3Schools.org-<
function getCookie(username){
	var cVal = document.cookie;
	var cBeg = cVal.indexOf(" " + username + "=");	//Uses IndexOf method
	if (cBeg == -1){
		cBeg = cVal.indexOf(username + "=");
	}
	if (cBeg == -1){
		cVal = null;
	}else{
		cBeg = cVal.indexOf("=", cBeg) + 1;
		var cEnd = cVal.indexOf(";", cBeg);
		if (cEnd == -1){
			cEnd = cVal.length;
		}
		cVal = unescape(cVal.substring(cBeg,cEnd));
		alert(username+" Logged in!"+cVal);
	}
	return cVal;
}	

//  --- Function to check for cookies (for log in) ---
function checkCookie(){
	var userName=getCookie(username);
	  if (userName!=null && userName!=""){
		  alert("Welcome again " + userName);
	  }else{
		  userName=prompt("Please enter your name:","");
	  }
}