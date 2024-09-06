#ifndef CAccessor_H
#define CAccessor_H

#ifndef GetAccessorPrivate
#define GetAccessorPrivate(type, name, Name)\
private: type name;\
public: const type &__restrict__ Name() const { return name; }
#endif

#ifndef GetAccessorPrivateStatic
#define GetAccessorPrivateStatic(type, name, Name)\
private: static type name;\
public: static const type &__restrict__ Name() { return name; }
#endif

#ifndef GetAccessorPrivateStaticPointer
#define GetAccessorPrivateStaticPointer(type, name, Name)\
private: static type *__restrict__ name;\
public: static type *Name() { return name; }
#endif

#ifndef GetAccessorProtected
#define GetAccessorProtected(type, name, Name)\
protected: type name;\
public: const type &__restrict__ Name() const { return name; }
#endif

#endif