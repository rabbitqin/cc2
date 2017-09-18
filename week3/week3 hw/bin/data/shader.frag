
uniform sampler2DRect tex0;

uniform float rand;

varying vec2 texCoord;


uniform vec2 u_mouse;
uniform vec2 u_resolution;


void main()
{
    
    
    vec2 pos = texCoord;
    
    //    pos *= 2.;
    //    pos = mod(pos,500.);
    
    // convergence effect
    vec4 col = texture2DRect(tex0,pos);
    vec4 col_r = texture2DRect(tex0,pos + vec2(-35.0*rand,0));
    vec4 col_l = texture2DRect(tex0,pos + vec2( -10.0*rand,0));
    vec4 col_g = texture2DRect(tex0,pos + vec2( -7.5*rand,0));
    
    
    col.b = col.b + col_r.b*max(1.0,sin(pos.x*2.0)*3.0)*rand;
    col.r = col.r + col_l.r*max(1.0,sin(pos.x*2.0)*3.0)*rand;
    col.g = col.g + col_g.g*max(1.0,sin(pos.x*2.0)*3.0)*rand;
    
    
    vec2 st = gl_FragCoord.st / u_resolution;
    
    vec2 s_mouse = u_mouse/u_resolution;
    
    vec2 s_res = vec2(u_resolution.y/u_resolution.x,u_resolution.y/u_resolution.y) * .2;
    
    float pct = length( (s_mouse-st) / s_res );
    
    pct =1.0-pct*pct;
    
    vec3 color = pct*vec3(0.2,0.2,0.2);
    
    gl_FragColor.rgba = col.rgba+ vec4(color,1.0);
    ;
    
}
