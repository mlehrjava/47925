// JavaScript Document
//Administrator Functions
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

//Searches for a specific cookie by name.
		function getCookie(cName){
			var cVal = document.cookie;
			var cBeg = cVal.indexOf(" " + cName + "=");
			if (cBeg == -1){
				cBeg = cVal.indexOf(cName + "=");
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
			}
			return cVal;
		}
		//Display results
		function results(){
			var cookies = getCookies();
			var cookieObj = JSON.parse(cookies)
			document.write("</br> Quiz Results </br>");
			for(var name in cookieObj){
			document.write(name+"="+cookieObj[name]+"<br/>");
		}
		}
		//To delete a cookie
		function deleteResult(){
				window.location.assign("Delete Cookie.html");
			}