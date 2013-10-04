#include <list>
#include <vector>
#include <map>
#include <stdexcept>


enum EContainerType {
    CT_LIST, CT_VECTOR, CT_MAP
};

template<class T, class Cmp=std::less<T>, EContainerType CType=CT_LIST>
class IJournal {
public:
    virtual ~IJournal() {}
    virtual void AddStudent(const T& t) = 0;
    virtual double GetStudentScore(const T& t) const = 0;
    virtual void SetStudentScore(const T& t, double score) = 0;
    virtual void DropStudent(const T& t) = 0;
};


template<class T, class Cmp, EContainerType CType>
class TInternalStorage;

template<class T, class Cmp>
class TInternalStorage<T, Cmp, CT_LIST> {
    std::list<T> List;
    const Cmp Comparator;
    
    typename std::list<T>::const_iterator FindIter(const T& t) const {
        for (typename std::list<T>::const_iterator it = List.begin(); it != List.end(); ++it) {
            if (!Comparator(it->Student, t.Student) && !Comparator(t.Student, it->Student))
                return it;
        }
        return List.end();
    }
    typename std::list<T>::iterator FindIter(const T& t) {
        for (auto it = List.begin(); it != List.end(); ++it) {
            if (!Comparator(it->Student, t.Student) && !Comparator(t.Student, it->Student))
                return it;
        }
        return List.end();
    }
public:
    TInternalStorage() 
        : List()
        , Comparator()
    {}

    void Add(const T& t) {
        List.push_back(t);
    }
    const T& Find(const T& t) const {
        const auto it = FindIter(t);
        if (it == List.end())
            throw std::out_of_range("can't find object");
        return *it;
    }
    T& Find(const T& t) {
        auto it = FindIter(t);
        if (it == List.end())
            throw std::out_of_range("can't find object");
        return *it;
    }
    void Drop(const T& t) {
        const auto it = FindIter(t);
        if (it != List.end())
            List.erase(it);
        else
            throw std::out_of_range("can't drop unknown object");
    }
};


template<class T, class Cmp=std::less<T>, EContainerType CType=CT_LIST>
class TJournal : public IJournal<T, Cmp, CType> {
    struct TInternalNode {
        T Student;
        double Score;
    };
    TInternalStorage<TInternalNode, Cmp, CType> InternalStorage;
public:
    TJournal() {}
    virtual ~TJournal() {}
    virtual void AddStudent(const T& t) { 
        TInternalNode node = (TInternalNode) {t, 0.0};
        InternalStorage.Add(node);
    }
    virtual double GetStudentScore(const T& t) const {
        TInternalNode toSearch = (TInternalNode) {t, 0.0};
        const TInternalNode& node = InternalStorage.Find(toSearch);
        return node.Score;
    }
    virtual void SetStudentScore(const T& t, double score) {
        TInternalNode toSearch = (TInternalNode) {t, 0.0};
        TInternalNode& node = InternalStorage.Find(toSearch);
        node.Score = score;
    }
    virtual void DropStudent(const T& t) {
        TInternalNode toSearch = (TInternalNode) {t, 0.0};
        InternalStorage.Drop(toSearch);
    }
};
