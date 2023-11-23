#include <stream/serialstreamer.hpp>

int main()
{
    SerialStreamer<WindowsSerialStreamer> s;
    s.init("\\\\.\\COM3",9600);
    while(true)
    {
        std::size_t bytesRec = s.ReadAvailableData();
        if(bytesRec>0)
        {
            for(int i = 0;i<bytesRec;i++)
            {
                std::cout<<std::hex<<((uint16_t)(s.recieveBuffer[i])& 0x00FF)<<" ";
                if(i && i%32==0)
                    std::cout<<std::endl;
            }
        }
    }
    return {};
}