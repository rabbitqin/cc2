var t = 0;  // time used to animate circle along the line
var dir = 1;  // direction moving
var gSize = 150;  // size of the graph

function setup() {
  createCanvas(window.innerWidth, window.innerHeight);
}


function draw(){
  background(100, 50, 200); 
 text("mouse on to trigger", 50, 50);
  // increase t in current direction
  t += .015 * dir;
  // reverse t if it becomes greater than 1 or less than 0
  if( t >= 1 || t <= 0){ dir *= -1; }
  push();
  translate(100,100);
    // draw the graph and animation passing in the function we want to use to ease as a parameter
    drawGraph(easeInOutQuad);
    drawLabel("easeInOutQuad");
    if(mouseX>100&&mouseX<250&&mouseY<250)
    drawAnimatedPoint(t,easeInOutQuad);
    // draw a nice label underneath
  pop();

push();
  translate(300,100);
    // draw the graph and animation passing in the function we want to use to ease as a parameter
    drawGraph(easeInOutQuint);
    drawLabel("easeInOutQuint");
    if(mouseX>300&&mouseX<450&&mouseY<250)
    drawAnimatedPoint(t,easeInOutQuint);
    // draw a nice label underneath
  pop();

push();
translate(500,100);
    // draw the graph and animation passing in the function we want to use to ease as a parameter
    drawGraph(easeInQuint);
    drawLabel("easeInQuint");
       if(mouseX>500&&mouseX<650&&mouseY<250)
    drawAnimatedPoint(t,easeInQuint);
    // draw a nice label underneath
  pop();

push();
translate(700,100);
    // draw the graph and animation passing in the function we want to use to ease as a parameter
    drawGraph(easeInOutQuart);
    drawLabel("easeInOutQuart");
    if(mouseX>700&&mouseX<850&&mouseY<250)
    drawAnimatedPoint(t,easeInOutQuart);
    // draw a nice label underneath
  pop();

push();
translate(900,100);
    // draw the graph and animation passing in the function we want to use to ease as a parameter
    drawGraph(easeOutQuart);
    drawLabel("easeOutQuart");
     if(mouseX>900&&mouseX<1050&&mouseY<250)
    drawAnimatedPoint(t,easeOutQuart);
    // draw a nice label underneath
  pop();

push();
translate(1100,100);
    // draw the graph and animation passing in the function we want to use to ease as a parameter
    drawGraph(easeOutQuad);
    drawLabel("easeOutQuad");
    if(mouseX>1100&&mouseX<1250&&mouseY<250)
    drawAnimatedPoint(t,easeOutQuad);
    // draw a nice label underneath
  pop();

}

function drawAnimatedPoint(t,easeFunction,options=null){
  var pct = easeFunction(t,options);
  var lerpPos = pct*gSize; // point A is 0 so only need to multily by point B which is at max graph size 
  var xPos = t * gSize;   // move in linear steps alon x axis
  var yPos = gSize - lerpPos;//var yPos = gSize - lerpPos+t*t*50; // beacause coord inverted
  fill(255);
  ellipse(xPos,yPos,10,10);
}


function drawGraph(easeFunction,options=null){
  noFill();
  stroke(255);
  // draw lines for graph on left and bottom
  line(0,0,0,gSize);
  line(0,gSize,gSize,gSize);

  beginShape();

  for(var i = 0; i < gSize; i+=2){
    
    var pct =(1 / gSize) * i;
    
    pct = easeFunction(pct,options);
    
    var lerpPos = pct*gSize;
    
    vertex(i,gSize-lerpPos); 
  }
  
  endShape();

}
function drawLabel(mytext){
  noStroke();
  fill(255);
  //stroke(255);
  textSize(14);
  text(mytext, 0, gSize+16);
}

function linear(t,options=null){ 
  return t; 
}

function easeInOutQuad(t) { return t<.5 ? 2*t*t : -1+(4-2*t)*t }

function easeInOutQuint (t) { return t<.5 ? 16*t*t*t*t*t : 1+16*(--t)*t*t*t*t }

function easeInQuint (t) { return t*t*t*t*t }

function easeInOutQuart (t) { return t<.5 ? 8*t*t*t*t : 1-8*(--t)*t*t*t }

function easeOutQuart (t) { return 1-(--t)*t*t*t }

function easeOutQuad(t) { return t*(2-t) }
