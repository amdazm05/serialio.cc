#ifndef _SERIALSTREAMER
#define _SERIALSTREAMER

#include <array>
#include <string>
#include <memory>
#include <vector>
#include <concepts>
#include <iostream>
#include <exception>
#include <optional>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #include <windows.h>
    #include <tchar.h>
    #include <winbase.h>
#endif
    template<class D>
    class SerialStreamer: std::enable_shared_from_this<SerialStreamer<D>>
    {
        public:
            SerialStreamer()
            {

            }
            ~SerialStreamer()
            {

            }
            void enableDelimeterSearchMode(bool condition)
            {
                static_cast<D*>(this)->enableDelimeterSearchMode(condition);
            }
            void setListOfDelimitersToFind(std::vector<uint32_t> && listofDelimiters)
            {
                static_cast<D*>(this)->setListOfDelimitersToFind(listofDelimiters);
            }
            void init(std::string && string,int baudRate)
            {
                static_cast<D*>(this)->init(std::move(string),baudRate);
            }   
            bool isAValidPacketAvailable()
            {
                return static_cast<D*>(this)->isAValidPacketAvailable();
            }
            std::size_t ReadAvailableData()
            {
                return static_cast<D*>(this)->ReadAvailableData();
            }
            void writeData(std::shared_ptr<char> dataToWrite, std::size_t bytesToWrite)
            {

            }
            std::array<char,1<<16> recieveBuffer;
        protected:
            //Must be a deterministic
            std::vector<uint32_t> listofDelimiters;
            std::unique_ptr<char> currentBufferLocation;
            D * child;

            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
            DCB dcb;
            HANDLE hCom;
            BOOL fSuccess;
            TCHAR *pcCommPort;
            #endif
    };

    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    class WindowsSerialStreamer : public SerialStreamer<WindowsSerialStreamer>
    {
        public:
            WindowsSerialStreamer();
            ~WindowsSerialStreamer();
            void enableDelimeterSearchMode(bool condition);
            void setListOfDelimitersToFind(std::vector<uint32_t> && listofDelimiters);
            void init(std::string && string,int baudrate);
            bool isAValidPacketAvailable();
            std::size_t ReadAvailableData();
            void writeData(std::shared_ptr<char> dataToWrite, std::size_t bytesToWrite);
    };
    #endif
/// Needing a non blocking mode
/// https://stackoverflow.com/questions/17217032/reading-blocking-mode-from-com-port-rs232
#endif