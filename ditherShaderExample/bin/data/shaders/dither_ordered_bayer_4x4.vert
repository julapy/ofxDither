#version 120

//
//  Created by Lukasz Karluk on 08/02/14.
//  http://julapy.com
//

varying vec2 texCoordVarying;

void main(void)
{
	texCoordVarying = gl_MultiTexCoord0.xy;
	gl_Position = ftransform();
}