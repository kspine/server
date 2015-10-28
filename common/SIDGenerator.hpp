#ifndef __SIDGENERATOR_H__
#define __SIDGENERATOR_H__

#include "../include/baseHeader.h"
/**
 * session generator 
 * sessionid is a unique id which is a number type of unsigned 
 * int32; the first 8bit indecate the serverid, the less 24bits 
 * is the session series number. 
 * 
 * @author root (10/28/2015)
 */
class SIDGenerator
{
public:
    static SIDGenerator* getInstance()
    {
        static SIDGenerator instance;
        return &instance;
    }

    void init(uint32 serverid, uint32 s_startid)
    {
        if (!m_IsInit)
        {
            m_startid = s_startid;
            m_curid = m_startid;
            m_serverid = serverid;

            m_IsInit = true;
        }
    }

    uint32 getServeridBySID(uint32 sid)
    {
        if (!m_IsInit)
        {
            return 0;
        }

        uint32 serverid = sid >> 24;
        return serverid;
    }

    uint32 generatorSid()
    {
        if (!m_IsInit)
        {
            return 0;
        }

        m_curid += 1;
        uint32 sid = m_serverid << 24 | m_curid;
        return sid;
    }

private:
    SIDGenerator() : m_IsInit(false)
    {

    }

    bool m_IsInit;
    uint32 m_startid;
    uint32 m_curid;
    uint32 m_serverid;
};

#endif
