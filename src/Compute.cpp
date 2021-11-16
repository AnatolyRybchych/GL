#include "../include/headers/Compute.h"


namespace GL
{
    namespace Compute
    {
        WorkSpaceSize ComputeManager::GetWorkSpaceSize()
        {
            WorkSpaceSize wss;
            glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, &wss.workGroupCountX);
            glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 1, &wss.workGroupCountY);
            glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 2, &wss.workGroupCountZ);
            glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, &wss.workGroupSizeX);
            glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, &wss.workGroupSizeY);
            glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, &wss.workGroupSizeZ);
            return wss;
        }
    }
}