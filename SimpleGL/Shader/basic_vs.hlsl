
cbuffer cbNeverChanges : register(b0)
{
	matrix View;
	matrix Projection;
	matrix World;
	float4 vMeshColor;
};

struct VS_INPUT
{
	float3 Pos : POSITION;
	float4 Color : COLOR;
};

struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float4 Color : COLOR;
};

PS_INPUT VS(VS_INPUT input)
{
	PS_INPUT output = (PS_INPUT)0;
	output.Pos = mul(float4(input.Pos.xyz, 1), World);
	output.Pos = mul(output.Pos, View);
	output.Pos = mul(output.Pos, Projection);
	output.Color = input.Color;

	return output;
}
