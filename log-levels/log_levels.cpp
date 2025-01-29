#include <string>

namespace log_line {

    std::string message(std::string line) {
        // return the message
        int colon_index = line.find(":");
        return line.substr(colon_index + 2);
    }

    std::string log_level(std::string line) {
        // return the log level
        int start_idx = line.find_first_of("[") + 1;
        int end_inx = line.find_last_of("]");
        return line.substr(start_idx, end_inx - start_idx);
    }

    std::string reformat(std::string line) {
        // return the reformatted message
        std::string result = message(line) + " " + "(" + log_level(line) + ")";
        return result;
    }
} // namespace log_line
