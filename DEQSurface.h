#pragma once
#include <d3dx9core.h>
#include <vector>
using namespace std;
struct DEQSTextures {
	vector<IDirect3DTexture9*> Texture;
};

class CDEQSurface
{
public:
	CDEQSurface(IDirect3DDevice9 *pD3DDevice);
	~CDEQSurface();
	void Render();
	void OnLostDevice();
	void OnResetDevice();
	void ReinitializeTextures();
private:
	void InitializeSprites();
	void InitializeLines();
	void InitializeFonts();
	void InitializeTextures();
	IDirect3DDevice9*  m_pD3DDevice;
	ID3DXSprite*	   m_pBackgroundSprite;
	ID3DXFont*		   m_pFont;
	ID3DXLine*		   m_pLine;
	vector<DEQSTextures> Textures;
	//IDirect3DTexture9* m_pBackgroundTexture;
	//IDirect3DTexture9* m_pTexture;
};

