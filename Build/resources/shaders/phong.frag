#version 430 core
in VS_OUT
{
    vec3 position;
    vec3 normal;
    vec2 texcoord;
} vs_in;

out vec4 outColor;

struct Material{
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light{
    vec4 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;

uniform vec3 tint;
uniform sampler2D textureSampler;


void main()
{
    //ambient
    vec3 ambient = light.ambient;
    //diffuse

    vec3 light_dir = normalize(vec3(light.position) - vs_in.position);

    float intensity = max(dot(light_dir, vs_in.normal), 0);
    vec3 diffuse = material.diffuse * light.diffuse * intensity;

    //specular
    vec3 specular = vec3(0);
    if(intensity > 0){
        vec3 view_dir = normalize(-vec3(vs_in.position));
        vec3 reflection = reflect(-light_dir, vs_in.normal);
        intensity = max(dot(view_dir, reflection), 0);
        intensity = pow(intensity, 64);
        specular = material.specular * light.specular * intensity;
    }

//    outColor = vec4(fs_color, 1.0) * vec4(tint, 1) * texture(textureSampler, fs_texcoord);
	outColor = texture(textureSampler, fs_texcoord);

}