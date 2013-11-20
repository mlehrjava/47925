// JavaScript Document

var myImg1 = [ " images/costA.png", "images/locA.png", "images/awardsA.png", "images/activestudentsA.png"];
var myImg2 = [ " images/Cost.png", " images/loc.png", "images/awards.png", "images/students.png"];

//var cost = document.getElementById("cost").onmouseover;
//var loc = document.getElementById("loc").onmouseover;

//var cost2 = document.getElementById("cost").onmouseout;
//var loc2 = document.getElementById("loc").onmouseout;

var cost = document.getElementById("cost");
var loc = document.getElementById("loc");

function onMouseOver(){
	
	//document.images["cost"].src = myImg1[0];
	
	var cost = document.getElementById("cost");
	var loc = document.getElementById("loc");


	if(cost){
	document.images["cost"].src = myImg1[0];
	}
	
	if(loc){
	document.images["loc"].src = myImg1[1];
	}

}

function onMouseOut() {

	var cost = document.getElementById("cost");
	var loc = document.getElementById("loc");
	
	//document.images["cost"].src = myImg2[0];
	
	if(cost){
	document.images["cost"].src = myImg2[0];
	}
	
	if(document.getElementById("loc")){
	document.images["loc"].src = myImg2[1];
	}

}

function onMouseOverLoc(){
	

	if(document.getElementById("loc")){
	document.images["loc"].src = myImg1[1];
	}

}

function onMouseOutLoc(){
	

	if(document.getElementById("loc")){
	document.images["loc"].src = myImg2[1];
	}

}

function onMouseOverAwards(){
	

	if(document.getElementById("awards")){
	document.images["awards"].src = myImg1[2];
	}

}

function onMouseOutAwards(){
	

	if(document.getElementById("awards")){
	document.images["awards"].src = myImg2[2];
	}

}

function onMouseOverStudents(){
	

	if(document.getElementById("students")){
	document.images["students"].src = myImg1[3];
	}

}

function onMouseOutStudents(){
	

	if(document.getElementById("students")){
	document.images["students"].src = myImg2[3];
	}

}


