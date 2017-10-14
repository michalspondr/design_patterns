#ifndef _BUILDER_DESIGN_PATTERN_
#define _BUILDER_DESIGN_PATTERN_

namespace pattern {

class Builder {
        public:
        // build something
        // not necessarily virtual
        virtual void buildPart() = 0;
};

}
#endif
