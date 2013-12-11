// JavaScript Document
function getAnswers(){
		//Declare variables for all answers
		//use get elements by name or ID for answer validation
		var answer1 = document.getElementById('Answer 1').value;
		var answer2 = document.getElementById('Answer 2').value;
		var answer3 = document.getElementById('Answer 3').value;
		var answer4 = document.getElementsByName("q4");
		var answer5 = document.getElementsByName("q5");
		var answer6 = document.getElementsByName("q6");
		var answer7 = document.getElementsByName("q7");
		var answer8 = document.getElementsByName("q8");
		var answer9 = document.getElementsByName("q9");
		//Start Counting Correct and Incorrect Answers
		var correct=0;
		var incorrect=0;
		
		//Answer for Question 1
		if(answer1=="9"){
			correct++;
			//document.write("Right1<br />");
		}else{
			incorrect++;
			//document.write("Wrong<br />");
			}
		//Answer for Question 2
		if(answer2=="Alderan"){
			correct++;
			//document.write("Right2<br />");
		}else{
			incorrect++;
			//document.write("Wrong<br />");
			}
		//Answer for Question 3
		if(answer3=="Greedo"){
			correct++;
			//document.write("Right3<br />");
		}else{
			incorrect++;
			//document.write("Wrong<br />");
			}
		
		//Answer for Question 4
	    var right4 = false;
	    for(var i = 0; i < answer4.length; i++) {
		    if(answer4[i].value == "right" && answer4[i].checked == true) {
			  right4 = true;
		    }
	    }
	    if(right4) {
		    correct++;
			//alert("You answered correctly");
	    } else {
			incorrect++;
		    //alert("Wrong answer");
	    }
		
		//Answer for Qeustion 5
		var right5 = false;
	    for(var i = 0; i < answer5.length; i++) {
		    if(answer5[i].value == "right" && answer5[i].checked == true) {
			  right5 = true;
		    }
	    }
	    if(right5) {
		    correct++;
			//alert("You answered correctly");
	    } else {
		    incorrect++;
			//alert("Wrong answer");
	    }
		
		//Answer for Question 6
		var right6 = false;
	    for(var i = 0; i < answer6.length; i++) {
		    if(answer6[i].value == "right" && answer6[i].checked == true) {
			  right6 = true;
		    }
	    }
	    if(right6) {
		    correct++;
			//alert("You answered correctly");
	    } else {
		    incorrect++;
			//alert("Wrong answer");
	    }
		
		//Answer for Question 7
		var right7 = false;
		var chkRight=0;
		var chkWrong=0;
		for(var i = 0; i < answer7.length; i++){
			if(answer7[i].value=="right" && answer7[i].checked){
				chkRight++;
			}else if(answer7[i].value=="wrong" && answer7[i].checked){
				chkWrong++;
				}
		}
			if(chkRight===3 && chkWrong===0){
				right7=true;
				}
		if(right7) {
			correct++;
	    } else {
			incorrect++;
	    }
		
		//Answer for Question 8
		var right8 = false;
		var chkRight8=0;
		var chkWrong8=0;
		for(var i = 0; i < answer8.length; i++){
			if(answer8[i].value=="right" && answer8[i].checked){
				chkRight8++;
			}else if(answer8[i].value=="wrong" && answer8[i].checked){
				chkWrong8++;
				}
		}
			if(chkRight8===3 && chkWrong8===0){
				right8=true;
				}
	    if(right8) {
			correct++;
	    } else {
			incorrect++;
	    }
		
		//Answer for Question 9
		var right9 = false;
		var chkRight9=0;
		var chkWrong9=0;
		for(var i = 0; i < answer9.length; i++){
			if(answer9[i].value=="right" && answer9[i].checked){
				chkRight9++;
			}else if(answer9[i].value=="wrong" && answer9[i].checked){
				chkWrong9++;
				}
		}
			if(chkRight9===3 && chkWrong9===0){
				right9=true;
				}
	    if(right9) {
			correct++;
	    } else {
			incorrect++;
	    }
	alert("Right Answers "+correct+"   Wrong Answers "+incorrect);
	}