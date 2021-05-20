#include <iostream>
#include <vector>
#include <stdarg.h>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <random>
#include "Output.h"
#include "Film.h"
#include "Cinema.h"
#include "Repertoire.h"
#include "funcs.h"
#define d(a) a[0] << a[1] << "." << a[2] << a[3] << "." << a.substr(4, 4)
#define rand(x) engine() % x
#define ctoi(j) atoi(string({ j[0] }).c_str())
using namespace std;

vector<Film> films;
vector<Cinema> cinemas;
vector<Repertoire> repertoires;

int main()
{
	std::mt19937 engine;
	engine.seed(std::time(nullptr));
	system("chcp 1251");
	cls();
	Output out;
	int x, y;
	get_all();
	for (;;)
	{
		out.put("��� ���������� ��������� �������� �� ��������� � ������� ����!");
		cinx(y, "�������� �������, � ������� �� ������ ��������:", 3, "����������", "������", "����������");
		switch (y)
		{
			case 1:
				{
					for (;;)
					{
						out.put("������ 1");
						cinx(x, "�������� ��������:", 4, "���������� ������� ����������", "���������� �������� ���������� �� �����",
							"����� �����������", "�������������� �����������");
						switch (x)
						{
							case 1:
								{
									out.put("������ ������� ����������:");
									for (Cinema &a: cinemas)
										a.show();
									out.put("������� ��� �����������");
									getchar();
									cls();
									break;
								}

							case 2:
								{
									int j;
									out.put("������� ���� ������� ��� ���������� ��� -1 ��� ������");
									r_cin(j);
									if (j == -1)
									{
										cls();
										break;
									}

									for (Cinema &a: cinemas)
									{
										if (j == a.id)
										{
											a.show();
											out.put("������� ��� �����������:");
											cc();
											getchar();
											cls();
											j = -1;
										}
									}

									if (j != -1)
									{
										out.put("���������� � ������ ������ �� ����������");
										out.put("������� ��� �����������:");
										cc();
										getchar();
										cls();
									}

									break;
								}

							case 3:
								{
									int j, i;
									string b;
									Cinema a(0);

									cinx(j, "�������� ��������, ������� �� �������, � �� �������� ����� ����������� �����:",
										8, "ID", "�������� ����������", "���-�� �����", "���-�� ����", "�����",
										"���������", "���������", "ID �����������");
									if (j == 0)
									{
										cls();
										break;
									}

									if (j == 1)
									{
										out.put("������� ID:");
										r_cin(a.id);
									}

									if (j == 2)
									{
										out.put("������� �������� ����������:");

										push_line(a.name);
									}

									if (j == 3)
									{
										out.put("������� ���-�� �����:");
										r_cin(a.halls);
									}

									if (j == 4)
									{
										out.put("������� ���-�� ����");
										r_cin(a.places);
									}

									if (j == 5)
									{
										out.put("������� �����:");
										push_line(a.address);
									}

									if (j == 6)
									{
										out.put("������� ���������:");
										push_line(a.category);
									}

									if (j == 7)
									{
										out.put("������� ���������:");
										r_cin(i);
										a.state = (i == 1);
									}

									if (j == 8)
									{
										out.put("������� ID ����������� ����� Enter ��� -1 ��� ������:");
										push_vector(a.reps);
									}

									cout << endl;
									a.find();

									break;
								}

							case 4:
								{
									out.put("������ 4");
									cinx(x, "�������� ��������:", 3, "�������� ���������", "������� ���������", "�������� ���������");

									switch (x)
									{
										case 1:
											{
												cinemas.push_back(Cinema());
												out.put("������� ��������");
												out.put("������� ��� �����������:");
												getchar();
												cls();
												break;
											}

										case 2:
											{
												for (;;)
												{
													int j;
													int x = rand(10);
													cinx(j, "������� ���� ������, ������� �� ������ ������� ��� -1 ��� ������:");
													if (j == -1)
													{
														cls();
														break;
													}

													for (auto it = films.begin(); it < films.end(); it++)
													{
														if ((*it).id == j)
														{
															out.put("����� ������� �� ������ �������:");
															(*it).show();
															cout << "��� ������������� �������� ������� " << x << " :";
															cinx(j, "");
															if (j == x)
															{
																films.erase(it);
																out.put("�����");
																j = -1337;
															}
															else
															{
																out.put("������");
																j = -1337;
															}

															break;
														}
													}

													if (j != -1337)
													{
														out.put("����� �� ��� ������");
													}
												}

												break;
											}

										case 3:
											{
												int j;
												int x;
												cinx(j, "������� ID ������, ������� ����� ��������:");
												for (size_t i = 0; i < films.size(); i++)
												{
													{
														if (films[i].id == j)
														{
															out.put("����� ������� �� ������ ��������:");
															films[i].show();
															for (;;)
															{
																cinx(x, "�������� �������� ��� ��� ������:", 6, "�������� ������",
																	"�������� ������", "���������", "���������", "�����", "������");
																if (x == 0)
																	break;
																if (x == 1)
																{
																	out.put("������� ��������:");
																	films[i].name.clear();
																	push_line(films[i].name);
																}

																if (x == 2)
																{
																	out.put("������� �������� ����������");
																	films[i].studio.clear();
																	push_line(films[i].studio);
																}

																if (x == 3)
																{
																	out.put("������� ���������� ����� Enter (-1 ��� ����������� �����)");
																	films[i].producers.clear();
																	push_vector(films[i].producers);
																}

																if (x == 4)
																{
																	out.put("������� ���������� ����� Enter (-1 ��� ����������� �����)");
																	films[i].opers.clear();
																	push_vector(films[i].opers);
																}

																if (x == 5)
																{
																	out.put("������� ����� ���� Enter (-1 ��� ����������� �����)");
																	films[i].genres.clear();
																	push_vector(films[i].genres);
																}

																if (x == 6)
																{
																	out.put("������� ������� ���� Enter (-1 ��� ����������� �����)");
																	films[i].actors.clear();
																	push_vector(films[i].actors);
																}

																out.put("�����");
															}

															out.put("���������� �����:");
															films[i].show();
															cc();
															out.put("������� ��� �����������");
															getchar();
															cls();
															break;
														}
													}
												}
											}

										default:
											break;
									}

									break;
								}

							default:
								{
									break;
								}
						}

						if (!x)
							break;
					}

					break;
				}

			case 2:
				{
					for (;;)
					{
						cinx(x, "�������� ��������:", 4, "���������� ������� ������", "���������� �������� ������ �� �����",
							"����� ������", "�������������� �������");
						switch (x)
						{
							case 1:
								{
									out.put("������ ������� �������:");
									for (Film &a: films)
										a.show();

									out.put("������� ��� �����������");
									getchar();
									cls();
									break;
								}

							case 2:
								{
									int j;
									out.put("������� ���� ������� ��� ������ ��� -1 ��� ������");
									r_cin(j);
									if (j == -1)
									{
										cls();
										break;
									}

									for (Film &a: films)
									{
										if (j == a.id)
										{
											a.show();
											out.put("������� ��� �����������:");
											cc();
											getchar();
											cls();
											j = -1;
										}
									}

									if (j != -1)
									{
										out.put("������ � ������ ������ �� ����������");
										out.put("������� ��� �����������:");
										cc();
										getchar();
										cls();
									}

									break;
								}

							case 3:
								{
									int j;
									string b;
									Film a(0);

									cinx(j, "�������� ��������, ������� �� �������, � �� �������� ����� ����������� �����:",
										7, "ID",
										"�������� ������", "�������� ������", "���������", "���������", "�����", "������");
									if (j == 0)
									{
										cls();
										break;
									}

									if (j == 1)
									{
										out.put("������� ID:");
										cin >> a.id;
									}

									if (j == 2)
									{
										out.put("������� �������� ������:");
										getline(cin, a.name);
									}

									if (j == 3)
									{
										out.put("������� �������� ������:");
										getline(cin, a.studio);
									}

									if (j == 4)
									{
										out.put("������� ���������� ����� �������:");
										getline(cin, b);

										a.producers = (e_parse(b));
									}

									if (j == 5)
									{
										out.put("������� ���������� ����� �������:");
										getline(cin, b);
										a.opers = (e_parse(b));
									}

									if (j == 6)
									{
										out.put("������� ����� ����� �������:");
										getline(cin, b);
										a.genres = (e_parse(b));
									}

									if (j == 7)
									{
										out.put("������� ������� ����� �������:");
										getline(cin, b);
										a.actors = (e_parse(b));
									}

									cout << endl;
									a.find();

									break;
								}

							case 4:
								{
									out.put("������ 4");
									cinx(x, "�������� ��������:", 3, "�������� �����", "������� �����", "�������� �����");

									switch (x)
									{
										case 1:
											{
												films.push_back(Film());
												out.put("������� ��������");
												out.put("������� ��� �����������:");
												getchar();
												cls();
												break;
											}

										case 2:
											{
												for (;;)
												{
													int j;
													int x = rand(10);
													cinx(j, "������� ���� ������, ������� �� ������ ������� ��� -1 ��� ������:");
													if (j == -1)
														cls();
													break;

													for (auto it = films.begin(); it < films.end(); it++)
													{
														if ((*it).id == j)
														{
															out.put("����� ������� �� ������ �������:");
															(*it).show();
															cout << "��� ������������� �������� ������� " << x << " :";
															cinx(j, "");
															if (j == x)
															{
																films.erase(it);
																out.put("�����");
																j = -1337;
															}
															else
															{
																out.put("������");
																j = -1337;
															}

															break;
														}
													}

													if (j != -1337)
													{
														out.put("����� �� ��� ������");
													}
												}

												break;
											}

										case 3:
											{
												int j;
												int x;
												cinx(j, "������� ID ������, ������� ����� ��������:");
												for (size_t i = 0; i < films.size(); i++)
												{
													{
														if (films[i].id == j)
														{
															out.put("����� ������� �� ������ ��������:");
															films[i].show();
															for (;;)
															{
																cinx(x, "�������� �������� ��� ��� ������:", 6, "�������� ������",
																	"�������� ������", "���������", "���������", "�����", "������");
																if (x == 0)
																	break;
																if (x == 1)
																{
																	out.put("������� ��������:");
																	films[i].name.clear();
																	push_line(films[i].name);
																}

																if (x == 2)
																{
																	out.put("������� �������� ����������");
																	films[i].studio.clear();
																	push_line(films[i].studio);
																}

																if (x == 3)
																{
																	out.put("������� ���������� ����� Enter (-1 ��� ����������� �����)");
																	films[i].producers.clear();
																	push_vector(films[i].producers);
																}

																if (x == 4)
																{
																	out.put("������� ���������� ����� Enter (-1 ��� ����������� �����)");
																	films[i].opers.clear();
																	push_vector(films[i].opers);
																}

																if (x == 5)
																{
																	out.put("������� ����� ���� Enter (-1 ��� ����������� �����)");
																	films[i].genres.clear();
																	push_vector(films[i].genres);
																}

																if (x == 6)
																{
																	out.put("������� ������� ���� Enter (-1 ��� ����������� �����)");
																	films[i].actors.clear();
																	push_vector(films[i].actors);
																}

																out.put("�����");
															}

															out.put("���������� �����:");
															films[i].show();
															cc();
															out.put("������� ��� �����������");
															getchar();
															cls();
															break;
														}
													}
												}
											}

										default:
											break;
									}

									break;
								}

							default:
								{
									break;
								}
						}

						if (!x)
							break;
					}

					break;
				}

			case 3:
				for (;;)
				{
					cinx(x, "�������� ��������:", 4, "���������� ������� ����������", "���������� �������� ���������� �� �����",
						"����� ����������", "�������������� �����������");
					switch (x)
					{
						case 1:
							{
								out.put("������ ������� �����������:");
								for (Repertoire &a: repertoires)
									a.show();
								//cout << "ID : " << a.id << ". �������� : " << a.name << ". ���� : " << unvector(a.genres) << "." << endl;
								out.put("������� ��� �����������");
								getchar();
								cls();
								break;
							}

						case 2:
							{
								int j;
								out.put("������� ���� ������� ��� ���������� ��� -1 ��� ������");
								r_cin(j);
								if (j == -1)
								{
									cls();
									break;
								}

								for (Repertoire &a: repertoires)
								{
									if (j == a.id)
									{
										a.show();
										out.put("������� ��� �����������:");
										cc();
										getchar();
										cls();
										j = -1;
									}
								}

								if (j != -1)
								{
									out.put("���������� � ������ ������ �� ����������");
									out.put("������� ��� �����������:");
									cc();
									getchar();
									cls();
								}

								break;
							}

						case 3:
							{
								int j, i;
								string b;
								Repertoire a(0);

								cinx(j, "�������� ��������, ������� �� �������, � �� �������� ����� ����������� �����:",
									5, "ID",
									"ID ������", "����", "����", "��������� �����");
								if (j == 0)
								{
									cls();
									break;
								}

								if (j == 1)
								{
									out.put("������� ID:");
									cin >> a.id;
								}

								if (j == 2)
								{
									out.put("������� ID ������ ����� Enter ��� -1:");
									while (i != -1)
									{
										r_cin(i);
										a.film = a.film->search(i);
									}
								}

								if (j == 3)
								{
									out.put("������� ���� � ������� ������ (��������, 30052021):");
									getline(cin, a.date);
								}

								if (j == 4)
								{
									out.put("������� ����");
									r_cin(i);

									a.price = i;
								}

								if (j == 5)
								{
									out.put("������� ���������� ��������� ����:");
									r_cin(i);

									a.free_places = i;
								}

								cout << endl;
								a.find();

								break;
							}

						case 4:
							{
								out.put("������ 4");
								cinx(x, "�������� ��������:", 3, "�������� ���������", "������� ���������", "�������� ���������");

								switch (x)
								{
									case 1:
										{
											repertoires.push_back(Repertoire());
											//films[films.size() - 1].save();	//
											out.put("������� ��������");
											out.put("������� ��� �����������:");
											getchar();
											cls();
											break;
										}

									case 2:
										{
											for (;;)
											{
												int j;
												int x = rand(10);
												cinx(j, "������� ���� ����������, ������� �� ������ ������� ��� -1 ��� ������:");
												if (j == -1)
												{
													cls();
													break;
												}

												for (auto it = repertoires.begin(); it < repertoires.end(); it++)
												{
													if ((*it).id == j)
													{
														out.put("��������� ������� �� ������ �������:");
														(*it).show();
														cout << "��� ������������� �������� ������� " << x << " :";
														cinx(j, "");
														if (j == x)
														{
															repertoires.erase(it);
															out.put("�����");
															j = -1337;
														}
														else
														{
															out.put("������");
															j = -1337;
														}

														break;
													}
												}

												if (j != -1337)
												{
													out.put("��������� �� ��� ������");
												}
											}

											break;
										}

									case 3:
										{
											int j;
											int x;
											cinx(j, "������� ID ����������, ������� ����� ��������:");
											for (size_t i = 0; i < repertoires.size(); i++)
											{
												{
													if (repertoires[i].id == j)
													{
														out.put("��������� ������� �� ������ ��������:");
														repertoires[i].show();
														for (;;)
														{
															cinx(x, "�������� �������� ��� ��� ������:", 4, "����",
																"ID ������", "����", "���-�� ��������� ����");
															if (x == 0)
																break;
															if (x == 1)
															{
																out.put("������� ���� � ������� ������ (��������, 30052021):");
																repertoires[i].date.clear();
																push_line(repertoires[i].date);
															}

															if (x == 2)
															{
																out.put("������� ID ������");
																r_cin(j);
																repertoires[i].film = repertoires[i].film->search(j);
															}

															if (x == 3)
															{
																out.put("������� ����");
																r_cin(repertoires[i].price);
															}

															if (x == 4)
															{
																out.put("������� ���-�� ��������� ����");
																r_cin(repertoires[i].free_places);
															}

															out.put("�����");
														}

														out.put("���������� ���������:");
														films[i].show();
														cc();
														out.put("������� ��� �����������");
														getchar();
														cls();
														break;
													}
												}
											}
										}

									default:
										break;
								}

								break;
							}

						default:
							{
								// cout << -12356889;
								break;
							}
					}

					if (!x)
						break;
				}

				break;
			default:
				set_all();
				return 0;
		}
	}
}
