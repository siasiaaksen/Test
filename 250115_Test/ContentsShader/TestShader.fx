struct EngineVertex
{
	float4 POSITION : POSITION;
	float4 UV : TEXCOORD;
	float4 COLOR : COLOR;
};

struct VertexShaderOutPut
{
	float4 SVPOSITION : SV_POSITION; 
	float4 UV : TEXCOORD; // 
	float4 COLOR : COLOR;
};

cbuffer FTransform : register(b0)
{
	// 변환용 벨류
	float4 Scale;
	float4 Rotation;
	float4 Qut;
	float4 Location;

	// 릴리에티브 로컬
	float4 RelativeScale;
	float4 RelativeRotation;
	float4 RelativeQut;
	float4 RelativeLocation;

	// 월드
	float4 WorldScale;
	float4 WorldRotation;
	float4 WorldQuat;
	float4 WorldLocation;

	float4x4 ScaleMat;
	float4x4 RotationMat;
	float4x4 LocationMat;
	float4x4 RevolveMat;
	float4x4 ParentMat;
	float4x4 LocalWorld;
	float4x4 World;
	float4x4 View;
	float4x4 Projection;
	float4x4 WVP;
};

VertexShaderOutPut Test_VS(EngineVertex _Vertex)
{
	VertexShaderOutPut OutPut;
	OutPut.SVPOSITION = mul(_Vertex.POSITION, WVP);
	OutPut.UV = _Vertex.UV;
	OutPut.COLOR = _Vertex.COLOR;
	return OutPut;
}

float4 Test_PS(VertexShaderOutPut _Vertex) : SV_Target0
{
	return _Vertex.COLOR;
};
