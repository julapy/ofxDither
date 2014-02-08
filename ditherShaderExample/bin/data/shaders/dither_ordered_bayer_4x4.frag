#version 120

//
//  Created by Lukasz Karluk on 08/02/14.
//  http://julapy.com
//

varying vec2 texCoordVarying;

uniform sampler2DRect tex0;
uniform bool bUseColor;

mat4x4 thresholdMatrix = mat4x4(1.0,  9.0,  3.0,  11.0,
                                13.0, 5.0,  15.0, 7.0,
                                4.0,  12.0, 2.0,  10.0,
                                16.0, 8.0,  14.0, 6.0);

void main()
{
    vec4 color = texture2DRect(tex0, texCoordVarying.xy);
    vec3 luminosity = vec3(0.30, 0.59, 0.11);
    float lum = dot(luminosity, color.rgb);
    
    float x = gl_FragCoord.x;
    float y = gl_FragCoord.y;
    
    int s = 4;
    int xi = int(mod(int(x), s));
    int yi = int(mod(int(y), s));
    
    float i = thresholdMatrix[xi][yi];
    float t = (i - 0.5) / float(s * s);
    
    vec4 dither = vec4(1.0, 1.0, 1.0, 1.0);
    if(lum < t) {
        if(bUseColor == true) {
            dither = color;
        } else {
            dither = vec4(0.0, 0.0, 0.0, 1.0);
        }
    }
    
    gl_FragColor = dither;
}
