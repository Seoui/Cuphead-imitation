cbuffer CB_PerFrame
{
	matrix View;
	matrix Projection;
}
matrix World;
float4 LineColor;

struct VertexInput
{
	float4 Position : POSITION0;
};

struct VertexOutput
{
	float4 Position : SV_POSITION0;
};

VertexOutput VS(VertexInput input)
{
	VertexOutput output;
	output.Position = mul(input.Position, World);
	output.Position = mul(output.Position, View);
	output.Position = mul(output.Position, Projection);

	return output;
}

float4 PS(VertexOutput input) : SV_TARGET0
{
	return LineColor;
}

technique11 T0
{
	pass P0
	{
		SetVertexShader(CompileShader(vs_5_0, VS()));
		SetPixelShader(CompileShader(ps_5_0, PS()));
	}
}