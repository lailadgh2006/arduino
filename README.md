# Đề tài: Đọc và hiệu chuẩn giá trị cảm biến FSR bằng phương pháp nội suy

## Mô tả dự án
Dự án cá nhân cài đặt đo và hiệu chuẩn giá trị từ cảm biến lực FSR (Force Sensitive Resistor) sang đơn vị Newton (N) trên bo mạch Arduino sử dụng phương pháp nội suy tuyến tính.

## Sơ đồ kết nối phần cứng (Pinout)
- **FSR Pin:** Nối chân Analog `A0` của Arduino
- **Baudrate:** 9600

## Chức năng
- Đọc giá trị ADC từ chân `A0`.
- Sử dụng bảng điểm hiệu chuẩn để tính toán lực tương ứng (đơn vị Newton).
- Xuất dữ liệu ra Serial Monitor.
