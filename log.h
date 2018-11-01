//
// Created by Shifeng,Zhang on 2018/10/25.
//

#ifndef KIME_LOG_H
#define KIME_LOG_H

/*
	日志级别
 */
enum _log_level {
    DEBUG = 0,
    INFO,
    WARN,
    ERROR
};

// 配置日志
int configure_log(int level, const char* file, int use_console);

// 打印日志
void logging(int lvl, const char *file, const int line, const char *fmt, ...);

#define debug(fmt, ...) logging(DEBUG, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define info(fmt, ...)  logging(INFO, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define warn(fmt, ...)  logging(WARN, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
// 错误信息
#define error(fmt, ...) logging(ERROR, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#endif //KIME_LOG_H
