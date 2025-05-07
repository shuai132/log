static void test_hex() {
  unsigned char data[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x00, 0x57, 0x6F,
                          0x72, 0x6C, 0x64, 0x1F, 0x0A, 0x7F, 0x21, 0x41,
                          0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x00};
  LOG("LOG_HEX:");
  LOG_HEX(data, sizeof(data));
  LOG("LOG_HEX_H:");
  LOG_HEX_H(data, sizeof(data));
  LOG("LOG_HEX_C:");
  LOG_HEX_C(data, sizeof(data));
  LOG("LOG_HEX_D:");
  LOG_HEX_D(data, sizeof(data));

  LOG("LOGD_HEX:");
  LOGD_HEX(data, sizeof(data));
  LOG("LOGD_HEX_H:");
  LOGD_HEX_H(data, sizeof(data));
  LOG("LOGD_HEX_C:");
  LOGD_HEX_C(data, sizeof(data));
  LOG("LOGD_HEX_D:");
  LOGD_HEX_D(data, sizeof(data));
}
