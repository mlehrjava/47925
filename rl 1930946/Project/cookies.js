function setCookie(cookieName, cookieValue, cookiePath, cookieExpires){
	
		cookieValue = escape(cookieValue);
		 
		 if(cookieExpires == " "){
			 
			 	var nowDate = new Date();
				nowDate.setMonth(nowDate.getMonth() +6);
				cookieExpires = nowDate.toGMTString();
				
			 }
			 
		if( cookiePath != " "){
			
			cookiePath = ";Path=" + cookiePath;
			
			}
			
		document.cookie = cookieName + "=" + cookieValue + ";expires=" + cookieExpires + cookiePath;
}

var Name = document.getElementById("Name").value;

setCookie(Name, "Hello", "", "");

alert(document.cookie);
