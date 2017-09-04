var img;
var lastX = 0;
var lastY = 0;

function setup() {
  createCanvas(window.innerWidth, window.innerHeight);
  img = loadImage("assets/2.jpg"); 
}

function draw(){

 //background(img);
 lastX = .99*lastX + .01*mouseX;
 lastY = .99*lastY + .01*mouseY;

  background(100, 50, 150); 
  image(img,50,50);
  //image(img,0,0,lastX,lastY);
}