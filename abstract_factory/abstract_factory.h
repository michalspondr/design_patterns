#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

#include <memory>

namespace pattern {

template <typename T>
class AbstractFactory {
        public:
        virtual std::unique_ptr<T> createProduct() = 0;
};

}

#endif
