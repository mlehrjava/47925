// JavaScript Document
// Mimics the $_GET array in PHP
	function getFormInfo(url){
		//Split information using ?
		var info=url.split("?");
		;
		//Take the second part for the
		//info array and split into
		//name-value pairs
		var nameValuePairs=info[1].split("&");
		//document.write("value right after split = "+nameValuePairs+"<p>")
		//var newValuepair = nameValuePairs[0].split(",");
		//document.write("second value right after split = "+newValuepair+"<p>")
		//Map the information to the Get Object
		var obj=new Object();
		for(var i=0;i<nameValuePairs.length-1;i++){
			var map=nameValuePairs[i].split("=");
			var name=map[0];
			//document.write("new list seprate with = "+name+"<p>");
			var value=map[1];
			//document.write("new list seprate with = "+value+"<p>");
			obj[name]=value;
		}
		return obj;
	}
	function savings(p,i,n){
		var sav=p;
		for(var j=1;j<=n;j++){
			sav*=(1+i/100);
		}
		return sav;
	}