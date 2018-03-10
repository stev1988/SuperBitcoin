#pragma once

#include <map>
#include <memory>
#include <thread>
#include "icomponent.h"
#include "utils/iterator.h"
#include "ui_interface.h"
#include "scheduler.h"
#include "interface/componentid.h"
#include "eventmanager/eventmanager.h"
#include "config/argmanager.h"

class CArgsManager;

class CChainParams;

class CBaseChainParams;

class ECCVerifyHandle;


namespace appbase
{
    class IBaseApp
    {
    public:

        virtual bool Initialize(int argc, char **argv) = 0;

        bool BaseInitialize(int argc, char **argv);

        bool InitializeLogging(fs::path path);

        static const CArgsManager &GetArgsManager()
        {
            return *pArgs.get();
        }

        static const CChainParams &GetChainParams()
        {
            return *pChainParams.get();
        }

    public:
        static log4cpp::Category &mlog;
    protected:
        static std::unique_ptr<CArgsManager> pArgs;
        static std::unique_ptr<CChainParams> pChainParams;
    };
}

const CArgsManager &Args();

const CChainParams &Params();

const CBaseChainParams &BaseParams();
