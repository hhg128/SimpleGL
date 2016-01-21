
Texture2D txDiffuse : register(t0);
SamplerState samLinear : register(s0);

struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float4 Color : COLOR;
};

float4 PS(PS_INPUT input) : SV_Target
{
	return input.Color;
}
