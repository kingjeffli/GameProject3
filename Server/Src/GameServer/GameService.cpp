﻿#include "stdafx.h"
#include "GameService.h"
#include "CommandDef.h"
#include "Log.h"
#include "CommonFunc.h"
#include "DataBuffer.h"
#include "CommonThreadFunc.h"
#include "../Message/Msg_ID.pb.h"
#include "../ConfigData/ConfigData.h"
#include "../Message/Msg_Game.pb.h"
#include "../Message/Msg_RetCode.pb.h"

CGameService::CGameService(void)
{

}

CGameService::~CGameService(void)
{
}

CGameService* CGameService::GetInstancePtr()
{
	static CGameService _GameService;

	return &_GameService;
}


BOOL CGameService::Init(UINT32 dwServerID, UINT32 dwPort)
{
	CommonFunc::SetCurrentWorkDir("");

	if(!CLog::GetInstancePtr()->StartLog("GameServer", "log"))
	{
		return FALSE;
	}

	CLog::GetInstancePtr()->LogError("---------服务器开始启动-ServerID:%d--Port:%d--------", dwServerID, dwPort);

	if(!CConfigFile::GetInstancePtr()->Load("servercfg.ini"))
	{
		CLog::GetInstancePtr()->LogError("配制文件加载失败!");
		return FALSE;
	}

	CLog::GetInstancePtr()->SetLogLevel(CConfigFile::GetInstancePtr()->GetIntValue("game_log_level"));

	m_dwServerID = dwServerID;

	INT32  nMaxConn = CConfigFile::GetInstancePtr()->GetIntValue("game_svr_max_con");
	if(!ServiceBase::GetInstancePtr()->StartNetwork(dwPort, nMaxConn, this))
	{
		CLog::GetInstancePtr()->LogError("启动服务失败!");
		return FALSE;
	}

	CConfigData::GetInstancePtr()->LoadConfigData("Config.db");


	if(!m_SceneManager.Init(TRUE))
	{
		CLog::GetInstancePtr()->LogError("启动场景管理器失败!");
		return FALSE;
	}

	CLog::GetInstancePtr()->LogError("---------服务器启动成功!--------");
	return TRUE;
}

BOOL CGameService::OnNewConnect(CConnection* pConn)
{
	if(pConn->GetConnectionID() == m_dwLogicConnID)
	{
		RegisterToLogicSvr();
		m_SceneManager.SendCityReport();
		return TRUE;
	}
	if(pConn->GetConnectionID() == m_dwProxyConnID)
	{
		RegisterToProxySvr();
		return TRUE;
	}

	return TRUE;
}

BOOL CGameService::OnCloseConnect(CConnection* pConn)
{
	if(m_dwLogicConnID == pConn->GetConnectionID())
	{
		m_dwLogicConnID = 0;
	}

	if(m_dwProxyConnID == pConn->GetConnectionID())
	{
		m_dwProxyConnID = 0;
	}

	return TRUE;
}

BOOL CGameService::OnSecondTimer()
{
	ConnectToLogicSvr();

	ConnectToProxySvr();

	return TRUE;
}

BOOL CGameService::DispatchPacket(NetPacket* pNetPacket)
{
	switch(pNetPacket->m_dwMsgID)
	{
			PROCESS_MESSAGE_ITEM(MSG_GASVR_REGTO_PROXY_ACK, OnMsgRegToProxyAck)
			PROCESS_MESSAGE_ITEM(MSG_WATCH_HEART_BEAT_REQ,  OnMsgWatchHeartBeatReq)
		default:
		{
			m_SceneManager.DispatchPacket(pNetPacket);
		}
		break;
	}

	return TRUE;
}

BOOL CGameService::Uninit()
{
	ServiceBase::GetInstancePtr()->StopNetwork();
	google::protobuf::ShutdownProtobufLibrary();
	return TRUE;
}

BOOL CGameService::Run()
{
	UINT64 uTickCount = 0;
	while(TRUE)
	{
		uTickCount = CommonFunc::GetTickCount();

		ServiceBase::GetInstancePtr()->Update();

		m_SceneManager.OnUpdate(uTickCount);

		CommonFunc::Sleep(1);
	}

	return TRUE;
}

BOOL CGameService::SetLogicConnID( UINT32 dwConnID )
{
	m_dwLogicConnID = dwConnID;

	return TRUE;
}

UINT32 CGameService::GetLogicConnID()
{
	return m_dwLogicConnID;
}

UINT32 CGameService::GetProxyConnID()
{
	return m_dwProxyConnID;
}

BOOL CGameService::ConnectToLogicSvr()
{
	if (m_dwLogicConnID != 0)
	{
		return TRUE;
	}
	UINT32 nLogicPort = CConfigFile::GetInstancePtr()->GetIntValue("logic_svr_port");
	std::string strLogicIp = CConfigFile::GetInstancePtr()->GetStringValue("logic_svr_ip");
	CConnection* pConn = ServiceBase::GetInstancePtr()->ConnectToOtherSvr(strLogicIp, nLogicPort);
	ERROR_RETURN_FALSE(pConn != NULL);
	m_dwLogicConnID = pConn->GetConnectionID();

	return TRUE;
}

BOOL CGameService::ConnectToProxySvr()
{
	if (m_dwProxyConnID != 0)
	{
		return TRUE;
	}
	UINT32 nProxyPort = CConfigFile::GetInstancePtr()->GetIntValue("proxy_svr_port");
	std::string strProxyIp = CConfigFile::GetInstancePtr()->GetStringValue("proxy_svr_ip");
	CConnection* pConn = ServiceBase::GetInstancePtr()->ConnectToOtherSvr(strProxyIp, nProxyPort);
	ERROR_RETURN_FALSE(pConn != NULL);
	m_dwProxyConnID = pConn->GetConnectionID();
	return TRUE;
}

BOOL CGameService::RegisterToLogicSvr()
{
	SvrRegToSvrReq Req;
	Req.set_serverid(m_dwServerID);
	return ServiceBase::GetInstancePtr()->SendMsgProtoBuf(m_dwLogicConnID, MSG_GAME_REGTO_LOGIC_REQ, 0, 0, Req);
}

BOOL CGameService::RegisterToProxySvr()
{
	SvrRegToSvrReq Req;
	Req.set_serverid(m_dwServerID);
	return ServiceBase::GetInstancePtr()->SendMsgProtoBuf(m_dwProxyConnID, MSG_GASVR_REGTO_PROXY_REQ, 0, 0, Req);
}

UINT32 CGameService::GetServerID()
{
	return m_dwServerID;
}

BOOL CGameService::OnMsgDefautReq(NetPacket* pNetPacket)
{
	return TRUE;
}

BOOL CGameService::OnMsgRegToProxyAck(NetPacket* pNetPacket)
{
	SvrRegToSvrAck Ack;

	Ack.ParsePartialFromArray(pNetPacket->m_pDataBuffer->GetData(), pNetPacket->m_pDataBuffer->GetBodyLenth());

	return TRUE;
}

BOOL CGameService::OnMsgWatchHeartBeatReq(NetPacket* pNetPacket)
{
	WatchHeartBeatReq Req;
	Req.ParsePartialFromArray(pNetPacket->m_pDataBuffer->GetData(), pNetPacket->m_pDataBuffer->GetBodyLenth());

	WatchHeartBeatAck Ack;

	Ack.set_data(Req.data());
	Ack.set_retcode(MRC_SUCCESSED);
	Ack.set_processid(CommonFunc::GetCurProcessID());
	ServiceBase::GetInstancePtr()->SendMsgProtoBuf(pNetPacket->m_dwConnID, MSG_WATCH_HEART_BEAT_ACK, 0, 0, Ack);

	return TRUE;
}
