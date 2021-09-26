/* FreeUpDiskSpace.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Collections;
import java.util.GregorianCalendar;
import java.util.List;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.File;

public class Prob22 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob22.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());
			
			GregorianCalendar today = new GregorianCalendar();
			today.set(Calendar.YEAR, 2019);
			today.set(Calendar.MONTH, Calendar.APRIL);
			today.set(Calendar.DAY_OF_MONTH, 27);
			today.set(Calendar.HOUR_OF_DAY, 0);
			today.set(Calendar.MINUTE, 0);
			today.set(Calendar.SECOND, 0);
			today.set(Calendar.MILLISECOND, 0);
			
			for (int testcase = 0; testcase < testCases; testcase++) {
				String volumeInformation = input.readLine();
				String[] volumeData = volumeInformation.split(" ");
				
				int numFiles = Integer.parseInt(volumeData[0]);
				double capacity = Double.parseDouble(volumeData[1]);
				List<FileData> files = new ArrayList<>();
				
				for(int i = 0; i < numFiles; i++) {
					FileData file = new FileData();
					
					String filetext = input.readLine();
					String[] fileinfo = filetext.split(" ");
					String[] dateParts = fileinfo[0].split("/");
					String ampm = fileinfo[2];
					file.size = Long.parseLong(fileinfo[3]);
					file.name = fileinfo[4];
					
					int day = Integer.parseInt(dateParts[0]);
					int month = Integer.parseInt(dateParts[1]);
					int year = Integer.parseInt(dateParts[2]);
					
					GregorianCalendar date = (GregorianCalendar) today.clone();
					date.set(Calendar.YEAR, year);
					date.set(Calendar.MONTH, month - 1);
					date.set(Calendar.DAY_OF_MONTH, day);
					date.set(Calendar.HOUR_OF_DAY, 12);
					
					int age = 0;
					
					while(date.before(today)) {
						age++;
						date.add(Calendar.DAY_OF_YEAR, 1);
					}
					
					double daysOld = age;
					if(ampm.equals("PM")) {
						daysOld -= 0.5;
					}
					
					file.score = daysOld * (file.size / 1000.0);
					file.score = Math.round(file.score * 1000.0) / 1000.0;
					
					files.add(file);
				}
				
				Collections.sort(files);
				
				double targetRemaining = capacity * 0.25;
				
				while(targetRemaining > 0.0 && !files.isEmpty()) {
					FileData file = files.remove(0);
					System.out.printf("%s %.3f\n", file.name, Double.valueOf(file.score));
					targetRemaining -= ((file.size / 1000.0) / 1000.0);
				}
			}
		}
	}

	private static class FileData implements Comparable<FileData>{
		public String name;
		public long size;
		public double score;
		
		public FileData() {
			// empty
		}
		
		@Override
		public int compareTo(FileData other) {
			if(this.score < other.score) {
				return 1;
			}
			if(this.score > other.score) {
				return -1;
			}
			return 0;
		}
	}
}
