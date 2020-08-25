#include <doctest/doctest.h>

#include <map>

// 146. LRU Cache
class LRUCache {
 private:
  struct List {
    struct Entry {
      Entry() : key{0}, value{0} {}
      Entry(int key, int value) : key(key), value(value) {}

      int key;
      int value;
      Entry* prev = nullptr;
      Entry* next = nullptr;
    };

    List() {
      head.next = &tail;
      tail.prev = &head;
    }

    void insert(Entry* entry) {
      entry->prev = &head;
      entry->next = head.next;
      head.next->prev = entry;
      head.next = entry;
    }

    Entry* insert(int key, int value) {
      auto entry = new Entry(key, value);
      insert(entry);
      return entry;
    }

    void remove(Entry* entry) {
      entry->prev->next = entry->next;
      entry->next->prev = entry->prev;
      entry->prev = nullptr;
      entry->next = nullptr;
    }

    Entry* back() { return tail.prev; }

    Entry head;
    Entry tail;
  };

  int capacity;
  List list;
  std::map<int, List::Entry*> map;

 public:
  LRUCache(int capacity) : capacity{capacity} {}

  int get(int key) {
    if (map.find(key) == map.end()) {
      return -1;
    }
    auto entry = map[key];
    list.remove(entry);
    list.insert(entry);
    return entry->value;
  }

  void put(int key, int value) {
    if (map.find(key) == map.end()) {
      if (static_cast<int>(map.size()) == capacity) {
        map.erase(list.back()->key);
        list.remove(list.back());
      }
      map[key] = list.insert(key, value);
    } else {
      map[key]->value = value;
      auto entry = map[key];
      list.remove(entry);
      list.insert(entry);
    }
  }
};

TEST_CASE("LRU Cache") {
  SUBCASE("Case 1") {
    LRUCache cache{2};
    cache.put(1, 1);
    cache.put(2, 2);
    REQUIRE_EQ(cache.get(1), 1);
    cache.put(3, 3);
    REQUIRE_EQ(cache.get(2), -1);
    cache.put(4, 4);
    REQUIRE_EQ(cache.get(1), -1);
    REQUIRE_EQ(cache.get(3), 3);
    REQUIRE_EQ(cache.get(4), 4);
  }

  SUBCASE("Case 2") {
    LRUCache cache{2};
    REQUIRE_EQ(cache.get(2), -1);
    cache.put(2, 6);
    REQUIRE_EQ(cache.get(1), -1);
    cache.put(1, 5);
    cache.put(1, 2);
    REQUIRE_EQ(cache.get(1), 2);
    REQUIRE_EQ(cache.get(2), 6);
  }

  SUBCASE("Case 3") {
    LRUCache cache{2};
    cache.put(2, 1);
    cache.put(1, 1);
    cache.put(2, 3);
    cache.put(4, 1);
    REQUIRE_EQ(cache.get(1), -1);
    REQUIRE_EQ(cache.get(2), 3);
  }
}
