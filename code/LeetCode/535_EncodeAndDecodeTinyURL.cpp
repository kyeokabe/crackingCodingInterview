class Solution {

private:
    unordered_map<string,string> m_long2short;
    unordered_map<string,string> m_short2long;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(m_long2short.find(longUrl)==m_long2short.end()){
            bool do_again=true;
            while(do_again){
                int temp=rand();
                string temp2="http://tinyurl.com/"+to_string(temp);
                if(m_short2long.find(temp2)==m_short2long.end()){
                    do_again=false;
                    m_short2long[temp2]=longUrl;
                    m_long2short[longUrl]=temp2;
                }
            }
            return m_long2short[longUrl];
        }
        else
            return m_long2short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m_short2long[shortUrl];
    }
};
