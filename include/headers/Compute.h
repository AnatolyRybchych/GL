#include "opengl.h"



namespace GL
{
    namespace Compute
    {
        struct WorkSpaceSize
        {
            int workGroupCountX;
            int workGroupCountY;
            int workGroupCountZ;
            int workGroupSizeX;
            int workGroupSizeY;
            int workGroupSizeZ;
        };

        class ComputeManager
        {
        public:
            static WorkSpaceSize GetWorkSpaceSize();
        };
    }
}