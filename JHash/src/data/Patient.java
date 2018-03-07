package data;

public class Patient implements Comparable<Patient>, Hospital {

	private int ticket;
	private String name;
	private Severity severity;

	public Patient(String name,Severity severity,int ticket) {
		this.name = name;
		this.severity = severity;
		this.ticket = ticket;
	}

	public void setTicket(int ticket) {
		this.ticket = ticket;
	}

	public int getTicket() {
		return this.ticket;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setReverity(Severity severity) {
		this.severity = severity;
	}

	@Override
	public String toString() {
		return "Patient [ticket=" + ticket + ", name=" + name + "]";
	}

	@Override
	public int compareTo(Patient other) {
		if (this.severity == other.severity) {
			return this.ticket - other.ticket;
		} else {
			return other.severity.getIndicator() - this.severity.getIndicator();
		}

	}

}
