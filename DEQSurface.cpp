#include "StdAfx.h"
#include <list>
#include <vector>
#include "DEQExternals.h"
#include "DEQSurface.h"
using namespace std;

CDEQSurface::CDEQSurface(IDirect3DDevice9 *pD3DDevice)
{

	m_pD3DDevice = pD3DDevice;
	m_pBackgroundSprite = NULL;
	m_pLine = NULL;
	m_pFont = NULL;
	/*for (int i=0;i<6;i++) {
		m_pBackgroundTexture[i] = NULL;
	}*/
	InitializeSprites();
	InitializeLines();
	InitializeFonts();
	ReinitializeTextures();
	bshowData=true;
	D3DXMatrixIdentity(&identityMatrix);
	m_pD3DDevice->SetRenderState(D3DRS_ZENABLE,D3DZB_FALSE);
}

void CDEQSurface::InitializeSprites()
{
	D3DXCreateSprite(m_pD3DDevice,&m_pBackgroundSprite);
}

void CDEQSurface::InitializeLines()
{
	D3DXCreateLine(m_pD3DDevice,&m_pLine);
}

void CDEQSurface::InitializeFonts()
{
	D3DXCreateFont( m_pD3DDevice, 18, 8, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &m_pFont );
}

void CDEQSurface::InitializeTextures()
{
	DEQSTextures empty;
	IDirect3DTexture9* myTexture; 
	for (int i=0; i<DEQSurfaceList.size(); i++) {
		Textures.push_back(empty);
		for (int j=0; j<DEQSurfaceList[i].DEQTextureList.size(); j++) {
		D3DXCreateTextureFromResourceEx(m_pD3DDevice,
		DEQSurfaceList[i].DEQTextureList[j].Handle,
		DEQSurfaceList[i].DEQTextureList[j].Sprite,
		DEQSurfaceList[i].DEQTextureList[j].Width,
		DEQSurfaceList[i].DEQTextureList[j].Height,
		0,
		NULL,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_POINT,
		D3DX_FILTER_NONE,
		0xFF000000,
		NULL,
		NULL,
		&myTexture);
		Textures[i].Texture.push_back(myTexture);
		}
	}
	/*D3DXCreateTextureFromResourceEx(m_pD3DDevice,
		gl_hThisInstance,
		MAKEINTRESOURCE(101),
		8,
		8,
		0,
		NULL,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_POINT,
		D3DX_FILTER_NONE,
		0xFF000000,
		NULL,
		NULL,
		&m_pBackgroundTexture[0]);
	D3DXCreateTextureFromResourceEx(m_pD3DDevice,
		gl_hThisInstance,
		MAKEINTRESOURCE(105),
		16,
		16,
		0,
		NULL,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_POINT,
		D3DX_FILTER_NONE,
		0xFF000000,
		NULL,
		NULL,
		&m_pBackgroundTexture[1]);
	D3DXCreateTextureFromResourceEx(m_pD3DDevice,
		gl_hThisInstance,
		MAKEINTRESOURCE(105),
		16,
		16,
		0,
		NULL,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_POINT,
		D3DX_FILTER_NONE,
		0xFF000000,
		NULL,
		NULL,
		&m_pBackgroundTexture[2]);
	D3DXCreateTextureFromResourceEx(m_pD3DDevice,
		gl_hThisInstance,
		MAKEINTRESOURCE(104),
		32,
		32,
		0,
		NULL,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_POINT,
		D3DX_FILTER_NONE,
		0xFF000000,
		NULL,
		NULL,
		&m_pBackgroundTexture[3]);
	D3DXCreateTextureFromResourceEx(m_pD3DDevice,
		gl_hThisInstance,
		MAKEINTRESOURCE(103),
		160,
		32,
		0,
		NULL,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_POINT,
		0xFF000000,
		NULL,
		NULL,
		&m_pBackgroundTexture[4]);
	D3DXCreateTextureFromResourceEx(m_pD3DDevice,
		gl_hThisInstance,
		MAKEINTRESOURCE(102),
		256,
		256,
		0,
		NULL,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_TRIANGLE,
		D3DX_FILTER_TRIANGLE,
		0xFF000000,
		NULL,
		NULL,
		&m_pBackgroundTexture[5]);*/

	/*HGLOBAL hResourceLoaded;  // handle to loaded resource
    HRSRC   hRes;
	LPCVOID     lpResLock;
	hRes = FindResource(gl_hThisInstance, MAKEINTRESOURCE(IDR_TGA1), "TGA");
    hResourceLoaded = LoadResource(gl_hThisInstance, hRes);
    lpResLock = (LPCVOID) LockResource(hResourceLoaded);
	D3DXCreateTextureFromFileInMemory(m_pD3DDevice,lpResLock,SizeofResource(gl_hThisInstance, hRes),&m_pBackgroundTexture[5]);*/

		/*Textures[0].Type=0;
		Textures[0].Height=8;
		Textures[0].Width=8;
		Textures[0].Frames=1;
		Textures[0].Angle=0;
		Textures[1].Type=1;
		Textures[1].Height=16;
		Textures[1].Width=16;
		Textures[1].Frames=1;
		Textures[1].Angle=0;
		Textures[2].Type=2;
		Textures[2].Frames=1;
		Textures[2].Height=16;
		Textures[2].Width=16;
		Textures[2].Angle=0;
		Textures[3].Type=3;
		Textures[3].Frames=9;
		Textures[3].Height=32;
		Textures[3].Width=32;
		Textures[3].Angle=10;
		Textures[4].Type=4;
		Textures[4].Frames=5;
		Textures[4].Height=32;
		Textures[4].Width=32;
		Textures[4].Angle=0;
		Textures[5].Type=5;
		Textures[5].Frames=1;
		Textures[5].Height=256;
		Textures[5].Width=256;
		Textures[5].Angle=0;*/
		//Textures[i].Height=m_pBackgroundTexture[i]->Height;
		//Textures[i].Width=m_pBackgroundTexture[i]->Width;
	//}
}
void CDEQSurface::ReinitializeTextures()
{
	//OutputDebugString("ReInitialize Textures\n");
	DEQSTextures empty;
	IDirect3DTexture9* myTexture; 
	Textures.clear();
	for (int i=0; i<DEQSurfaceList.size(); i++) {
		//OutputDebugString("ADDING ARRAY\n");
		Textures.push_back(empty);
		//OutputDebugString("ARRAY ADDED\n");
		for (int j=0; j<DEQSurfaceList[i].DEQTextureList.size(); j++) {
		//OutputDebugString("NEW TEXTURE\n");
		D3DXCreateTextureFromResourceEx(m_pD3DDevice,
		DEQSurfaceList[i].DEQTextureList[j].Handle,
		DEQSurfaceList[i].DEQTextureList[j].Sprite,
		DEQSurfaceList[i].DEQTextureList[j].Width,
		DEQSurfaceList[i].DEQTextureList[j].Height,
		0,
		NULL,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		DEQSurfaceList[i].DEQTextureList[j].Filter,
		DEQSurfaceList[i].DEQTextureList[j].MipFilter,
		DEQSurfaceList[i].DEQTextureList[j].ColorKey,//0xFF000000,
		NULL,
		NULL,
		&myTexture);
		Textures[i].Texture.push_back(myTexture);
		}
	}
}
CDEQSurface::~CDEQSurface()
{
	if (m_pFont) m_pFont->Release();
	if (m_pBackgroundSprite) m_pBackgroundSprite->Release();
	if (m_pLine) m_pLine->Release();
	/*for (int i=0;i<DEQTextureList.size();i++) {
		if (DEQTextureList[i].Texture) DEQTextureList[i].Texture->Release();
		//m_pBackgroundTexture[i] = NULL;
	}*/
	for (int i=0; i<Textures.size(); i++) {
		for (int j=0; j<Textures[i].Texture.size(); j++) {
			//Textures[i].Texture[j]->Release;
		}
	}
	Textures.clear();
	m_pBackgroundSprite = NULL;
	m_pLine = NULL;
	m_pFont = NULL;
}

void CDEQSurface::Render()
{
#if 1
	int j=0;
	DWORD state1,state2,state3;
	m_pD3DDevice->GetRenderState(D3DRS_ALPHABLENDENABLE,&state1);
	m_pD3DDevice->GetRenderState(D3DRS_SRCBLEND,&state2);
	m_pD3DDevice->GetRenderState(D3DRS_DESTBLEND,&state3);

	m_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,true);
	m_pD3DDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
	m_pD3DDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
	//m_pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG1,D3DTA_TEXTURE);

	m_pD3DDevice->BeginScene();

	for (int i=0;i<DEQSurfaceList.size();i++){
		if (!DEQSurfaceList[i].free){
			D3DXMATRIX mMyMatrix;

			D3DXMatrixRotationZ( &DEQSurfaceList[i].mRotation, D3DXToRadian(DEQSurfaceList[i].myAngle) );

			mMyMatrix = DEQSurfaceList[i].mRotation*DEQSurfaceList[i].mScale*DEQSurfaceList[i].mTranslation;

			//m_pLine->SetWidth(DEQSurfaceList[i].myScale);
			m_pLine->Begin();
			for (j=0;j<DEQSurfaceList[i].myLineList.index;j++){
				m_pD3DDevice->SetTransform( D3DTS_WORLD, &mMyMatrix );
				m_pLine->Draw(DEQSurfaceList[i].myLineList.line[j].myVerts, 2, DEQSurfaceList[i].myLineList.line[j].myColor );
			}
			m_pLine->End();

			D3DXMATRIX mTemp,mTempTranslation,mTempTranslationBack,mTempRotation,mTempCorrection,mTempScale;

			m_pBackgroundSprite->Begin(D3DXSPRITE_ALPHABLEND);
			//m_pBackgroundSprite->SetTransform(&mMyMatrix);
			for (j=0;j<DEQSurfaceList[i].myVectorList.index;j++){
				//OutputDebugString("Drawing vector\n");
				RECT tempRect;
				int tempFrame;
				int mFrame = GetFrameTime(DEQSurfaceList[i].DEQTextureList[DEQSurfaceList[i].myVectorList.vector[j].myType].Frames,50);
				D3DXMatrixRotationZ( &mTempRotation, D3DXToRadian(DEQSurfaceList[i].myVectorList.vector[j].myAngle+mFrame*DEQSurfaceList[i].DEQTextureList[DEQSurfaceList[i].myVectorList.vector[j].myType].Angle));
				D3DXMatrixScaling(&mTempScale,DEQSurfaceList[i].myVectorList.vector[j].myScale,DEQSurfaceList[i].myVectorList.vector[j].myScale,0);
				D3DXMatrixTranslation(&mTempTranslation,-DEQSurfaceList[i].myVectorList.vector[j].myVector.x,-DEQSurfaceList[i].myVectorList.vector[j].myVector.y,0);
				D3DXMatrixTranslation(&mTempTranslationBack,DEQSurfaceList[i].myVectorList.vector[j].myVector.x,DEQSurfaceList[i].myVectorList.vector[j].myVector.y,0);				
				D3DXMatrixTranslation(&mTempCorrection,DEQSurfaceList[i].myVectorList.vector[j].xCorr,DEQSurfaceList[i].myVectorList.vector[j].yCorr,0);
				//mTemp=mTempCorrection*mTempTranslation*mTempRotation*mTempTranslationBack*mMyMatrix;
				//D3DXMatrixTranslation(&mTempCorrection,DEQSurfaceList[i].myVectorList.vector[j].xCorr*DEQSurfaceList[i].myVectorList.vector[j].myScale,DEQSurfaceList[i].myVectorList.vector[j].yCorr*DEQSurfaceList[i].myVectorList.vector[j].myScale,0);
				mTemp=mTempCorrection*mTempTranslation*mTempRotation*mTempScale*mTempTranslationBack*DEQSurfaceList[i].mRotation*DEQSurfaceList[i].mScale*DEQSurfaceList[i].mTranslation;
				m_pBackgroundSprite->SetTransform(&mTemp);
				tempRect.top=0;
				tempRect.bottom=DEQSurfaceList[i].DEQTextureList[DEQSurfaceList[i].myVectorList.vector[j].myType].Height;
				if (mFrame>(DEQSurfaceList[i].DEQTextureList[DEQSurfaceList[i].myVectorList.vector[j].myType].Frames-1) || DEQSurfaceList[i].DEQTextureList[DEQSurfaceList[i].myVectorList.vector[j].myType].Angle>0) tempFrame=0;
				else tempFrame=mFrame;
				tempRect.left=DEQSurfaceList[i].DEQTextureList[DEQSurfaceList[i].myVectorList.vector[j].myType].FWidth*tempFrame;
				tempRect.right=DEQSurfaceList[i].DEQTextureList[DEQSurfaceList[i].myVectorList.vector[j].myType].FWidth*tempFrame+DEQSurfaceList[i].DEQTextureList[DEQSurfaceList[i].myVectorList.vector[j].myType].FWidth;
				/*char temp[1000];
				sprintf(temp,"\nTextures[i].Texture.size()=%d>DEQSurfaceList[i].myVectorList.vector[j].myType=%d\n",Textures[i].Texture.size(),DEQSurfaceList[i].myVectorList.vector[j].myType);
				OutputDebugString(temp);*/
				if (Textures.size()>i) {
					if (Textures[i].Texture.size()>DEQSurfaceList[i].myVectorList.vector[j].myType) {
					m_pBackgroundSprite->Draw(Textures[i].Texture[DEQSurfaceList[i].myVectorList.vector[j].myType],&tempRect,&DEQSurfaceList[i].myCenter,&DEQSurfaceList[i].myVectorList.vector[j].myVector,DEQSurfaceList[i].myVectorList.vector[j].myColor);
					}
				}
			}
			m_pBackgroundSprite->End();

			for (j=0;j<DEQSurfaceList[i].myTextList.index;j++){
				m_pFont->DrawText(NULL, DEQSurfaceList[i].myTextList.text[j].text, -1, &DEQSurfaceList[i].myTextList.text[j].rct, 0, DEQSurfaceList[i].myTextList.text[j].myColor );
			}

#ifdef _DEBUG

			if (bshowData){
				char tempString[64];
				myDataTextList.clear();
				tempText.rct.top=0;
				tempText.rct.left=0;
				tempText.rct.right=0+300;
				tempText.rct.bottom=0+20;
				sprintf_s(tempString,"L%d T%d V%d",DEQSurfaceList[0].myLineList.index,DEQSurfaceList[0].myTextList.index,DEQSurfaceList[0].myVectorList.index);
				strcpy_s(tempText.text,tempString);
				myDataTextList.push_back(tempText);
				m_pD3DDevice->SetTransform( D3DTS_WORLD, &identityMatrix );
				for (list<DEQD3DText>::iterator it = myDataTextList.begin();it != myDataTextList.end(); it++){
					tempText=*it;
					m_pFont->DrawText(NULL, tempText.text, -1, &tempText.rct, 0, 0xf0ffffff );
				}
			}
#endif
			DEQSurfaceList[i].updated=false;
		}
	}

	m_pD3DDevice->EndScene();
	m_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,state1);
	m_pD3DDevice->SetRenderState(D3DRS_SRCBLEND,state2);
	m_pD3DDevice->SetRenderState(D3DRS_DESTBLEND,state3);
#endif
}

void CDEQSurface::OnLostDevice()
{
	m_pBackgroundSprite->OnLostDevice();
	m_pFont->OnLostDevice();
	m_pLine->OnLostDevice();
}

void CDEQSurface::OnResetDevice()
{
	m_pBackgroundSprite->OnResetDevice();
	m_pFont->OnResetDevice();
	m_pLine->OnResetDevice();
}

