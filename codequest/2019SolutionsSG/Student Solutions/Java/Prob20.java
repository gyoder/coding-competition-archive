import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Prob20 {

	public static void main(String[] args) throws IOException{
		
		BufferedReader reader = new BufferedReader(new InputStreamReader( System.in ));
		PrintWriter writer = new PrintWriter(System.out);
		
		int T;
		
		T = Integer.valueOf(reader.readLine());
		
		for(int t = 0; t < T; t++) {
			int G, N;
			StringTokenizer st = new StringTokenizer(reader.readLine(), " ");
			G = Integer.valueOf(st.nextToken());
			N = Integer.valueOf(st.nextToken());
			
			HashMap<String, Integer> strToLoc = new HashMap<String, Integer>();
			int currCount = 0;
			
			ArrayList<bird> birds = new ArrayList<bird>();
			
			for(int i = 0; i < G; i++) {
				st = new StringTokenizer(reader.readLine(), " ");
				bird b = new bird(st.nextToken(), Double.valueOf(st.nextToken()), Double.valueOf(st.nextToken()), Double.valueOf(st.nextToken()), Double.valueOf(st.nextToken()));
				birds.add(b);
				if(!strToLoc.containsKey(b.name)) {
					strToLoc.put(b.name, currCount);
					currCount++;
				}
			}
			
			for(int i = 0; i < N; i++) {
				st = new StringTokenizer(reader.readLine(), " ");
				double ll = Double.valueOf(st.nextToken());
				double lw = Double.valueOf(st.nextToken());
				double lwn = Double.valueOf(st.nextToken());
				double lwa = Double.valueOf(st.nextToken());
				
				PriorityQueue<searchObj> pq = new PriorityQueue<searchObj>();
				
				for(int  j = 0; j < G; j++) {
					double dist = Math.sqrt(Math.pow(birds.get(j).l - ll, 2) + Math.pow(birds.get(j).w - lw, 2)
						+ Math.pow(birds.get(j).wn - lwn, 2) + Math.pow(birds.get(j).wa - lwa, 2));
					searchObj toInsert = new searchObj(birds.get(j).name, dist);
					pq.add(toInsert);
				}
				//We have a queue with the least distance first
				int[] count = new int[currCount + 5];
				
				for(int j = 0; j < 4; j++) {
					searchObj so = pq.poll();
					int loc = strToLoc.get(so.name);
					count[loc]++;
				}
				
				boolean two = true;
				int maxVal, maxPos = 0;
				while(two) {
					two = false;
					searchObj so = pq.poll();
					int loc = strToLoc.get(so.name);
					count[loc]++;
					maxVal = count[0];
					maxPos = 0;
					for(int k = 1; k < count.length; k++) {
						if(count[k] > maxVal) {
							maxVal = count[k];
							maxPos = k;
							two = false;
						}else if(count[k] == maxVal) {
							two = true;
						}
					}
				}
				
				for(String key : strToLoc.keySet()) {
					if(strToLoc.get(key) == maxPos) {
						writer.println(key);
					}
				}
			}
		}
		
		reader.close();
		writer.close();
	}
}

class bird {
	String name;
	double l, w, wn, wa;
	
	public bird (String name, double l, double w, double wn, double wa) {
		this.name = name;
		this.l = l;
		this.w = w;
		this.wn = wn;
		this.wa = wa;
	}
}

class searchObj implements Comparable<searchObj>{

	String name;
	double dist;
	
	public searchObj(String name, double dist) {
		this.name = name;
		this.dist = dist;
	}
	
	@Override
	public int compareTo(searchObj o) {
		// TODO Auto-generated method stub
		if(this.dist - o.dist >= 0) {
			return 1;
		}
		else {
			return -1;
		}
	}
	
}