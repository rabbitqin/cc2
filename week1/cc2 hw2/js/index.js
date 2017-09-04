var size = 0;
var t = 1;
var r = 0;
var dir = 1;

var smoothX = 10;

function setup() {
  createCanvas(window.innerWidth, window.innerHeight);
}

function draw(){
if(mouseX>window.innerWidth/2)
  smoothX = .99*smoothX + .01*(mouseX-window.innerWidth/2);
else
  smoothX = .99*smoothX + .01*(window.innerWidth/2-mouseX);
  //smoothY = .99*smoothY + .01*mouseY;

  background(200, 30, 50); 
  text("move mouse to change size", 615,50);
  fill(100, 150, 200, 255);
  noStroke();
  ellipse(window.innerWidth/2, window.innerHeight/2,smoothX,smoothX);
}