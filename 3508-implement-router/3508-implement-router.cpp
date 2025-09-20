
struct Packet {
    int source, dest, ts;
};

struct Hash {
    size_t operator()(const tuple<int,int,int> &t) const {
        auto [a,b,c] = t;
        return ((size_t)a * 1315423911u) ^ ((size_t)b * 2654435761u) ^ ((size_t)c);
    }
};
class Router {
public:
    int limit;
    deque<Packet> q;
    unordered_set<tuple<int,int,int>, Hash> st;            
    unordered_map<int, vector<int>> timeing;    

    Router(int memoryLimit) : limit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> key = {source, destination, timestamp};
        if (st.count(key)) return false;

        if ((int)q.size() >= limit) {
            Packet old = q.front();
            q.pop_front();
            st.erase({old.source, old.dest, old.ts});
            auto &vec = timeing[old.dest];
            if (!vec.empty() && vec.front() == old.ts) {
                vec.erase(vec.begin());  
            }
        }

        q.push_back({source, destination, timestamp});
        st.insert(key);
        timeing[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};

        Packet pkt = q.front();
        q.pop_front();
        st.erase({pkt.source, pkt.dest, pkt.ts});

        auto &vec = timeing[pkt.dest];
        if (!vec.empty() && vec.front() == pkt.ts) {
            vec.erase(vec.begin());
        }

        return {pkt.source, pkt.dest, pkt.ts};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = timeing.find(destination);
        if (it == timeing.end()) return 0;
        auto &vec = it->second;
        if (vec.empty()) return 0;

        auto low = lower_bound(vec.begin(), vec.end(), startTime);
        auto high = upper_bound(vec.begin(), vec.end(), endTime);
        return high - low;
    }
};