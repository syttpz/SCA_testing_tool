import serial
import csv


PORT = 'COM4'        
BAUD = 115200
TRACES_TO_COLLECT = 300
OUTPUT_FILE = "traces.csv"

ser = serial.Serial(PORT, BAUD, timeout=1)

print(f"Saving {TRACES_TO_COLLECT} traces to {OUTPUT_FILE}")
with open(OUTPUT_FILE, mode='w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    count = 0

    while count < TRACES_TO_COLLECT:
        line = ser.readline().decode('utf-8').strip()

        if line.startswith("PT:") and ",TRACE:" in line:
            try:
                pt_part, trace_part = line.split(",TRACE:")
                pt_hex = pt_part.replace("PT:", "")
                plaintext = [int(pt_hex[i:i+2], 16) for i in range(0, 32, 2)]
                trace = [int(x) for x in trace_part.split(",")]
                writer.writerow(plaintext + trace)
                count += 1
                #print(f"[{count}/{TRACES_TO_COLLECT}] Trace saved.")
            except Exception as e:
                print("Parse error:", e)

ser.close()